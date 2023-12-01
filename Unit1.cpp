//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include <windows.h>
#include <TlHelp32.h>
#include <IniFiles.hpp>
#include <Registry.hpp>
#include <System.JSON.hpp>
#include <System.StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TMemIniFile* Settings;
String serversFile = "servers.json";
bool MonitoringStarted = false;
String CurDate,LastRestart;
FILE *logFile;
TJSONArray *serversArray; // только для мониторинга
TMonitoringThread *monitoringThread;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	MainForm->Top = 0;
	MainForm->Left = 0;
	MainForm->Caption=Application->Title;

	// загружаем настройки из ini
	if (FileExists(ExtractFilePath(Application->ExeName)+"settings.ini"))
	{
		Settings = new TMemIniFile(ExtractFilePath(Application->ExeName) + "settings.ini", TEncoding::UTF8);
		RestartCheck->Checked = Settings->ReadBool("Options", "RestartDaily", 0);
		HourEdit->Text = Settings->ReadString("Options", "RestartHour", "04");
		MinEdit->Text = Settings->ReadString("Options", "RestartMinute", "00");
		IntEdit->Text = Settings->ReadString("Options", "Interval", 60);
		DownEdit->Text = Settings->ReadString("Options", "DownCount", 1);
		AutostartCheck->Checked = Settings->ReadBool("Options", "AutoStartMon", 0);
		HideCheck->Checked = Settings->ReadBool("Options", "Minimized", 0);
		LogCheck->Checked = Settings->ReadBool("Options", "Logging", 0);
		AutorunCheck->Checked = Settings->ReadBool("Options", "AutoRun", 0);
		MainForm->Top = Settings->ReadInteger("Position", "Top", 0);
		MainForm->Left = Settings->ReadInteger("Position", "Left", 0);
		delete Settings;
	}

	if (MainForm->Top == 0 && MainForm->Left == 0) {
        MainForm->Position = poScreenCenter;
	}

	// загружаем список серверов
    LoadServers();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LoadServers() {
	Servers->Items->Clear();
	if (FileExists(serversFile)) {
		TStringList *fileContent = new TStringList;
		try {
			fileContent->LoadFromFile(serversFile);
			String jsonData = fileContent->Text;
			TJSONArray *jsonArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
			if (jsonArray != nullptr) {
				Servers->Items->BeginUpdate();
				for (int i = 0; i < jsonArray->Count; i++) {
					TJSONObject *server = static_cast<TJSONObject*>(jsonArray->Get(i));
					String ip = server->GetValue("ip")->Value();
					String port = server->GetValue("port")->Value();
					TListItem *item = Servers->Items->Add();
					item->Caption = "";
					item->SubItems->Add(ip);
					item->SubItems->Add(port);
				}
				Servers->Items->EndUpdate();
			}
			delete jsonArray;
		}
		__finally {
			delete fileContent;
		}
	}
}
//---------------------------------------------------------------------------

void AddToStartup() {
	AnsiString appName = Application->Title;
	AnsiString appPath = Application->ExeName;
	std::unique_ptr<TRegistry> reg(new TRegistry());
	reg->RootKey = HKEY_CURRENT_USER;
	try {
		if (reg->OpenKey("\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", true)) {
			if (!reg->ValueExists(appName)) reg->WriteString(appName, appPath);
			reg->CloseKey();
		}
	}
	catch (const Exception& e) {
		Application->MessageBox(e.Message.c_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void RemoveFromStartup() {
	AnsiString appName = Application->Title;
	std::unique_ptr<TRegistry> reg(new TRegistry());
	reg->RootKey = HKEY_CURRENT_USER;
	try {
		if (reg->OpenKey("\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", false)) {
			if (reg->ValueExists(appName)) reg->DeleteValue(appName);
			reg->CloseKey();
		}
	}
	catch (const Exception& e) {
		Application->MessageBox(e.Message.c_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (HideCheck->Checked) Application->Minimize();
	if (AutostartCheck->Checked) StartButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StartButtonClick(TObject *Sender)
{
	if (MonitoringStarted == false) {
		if (Servers->Items->Count == 0) {
			Application->MessageBox(L"Сервера для мониторинга отсутствуют!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			return;
		}
		if (StrToInt(IntEdit->Text) < 60) {
			Application->MessageBox(L"Минимальный интервал мониторинга: 60 секунд", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
			IntEdit->Text = "60";
			return;
		}
		if (StrToInt(DownEdit->Text) < 1) {
			Application->MessageBox(L"Минимальное число неудачных попыток: 1", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
			DownEdit->Text = "1";
			return;
		}
		if (RestartCheck->Checked) {
			if (StrToInt(HourEdit->Text) > 23 || StrToInt(MinEdit->Text) > 59) {
				Application->MessageBox(L"Неверное время перезапуска сервера!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
				HourEdit->Text = "00";
				MinEdit->Text = "00";
				return;
			}
		}

		// сохранение настроек в ini
		Settings = new TMemIniFile(ExtractFilePath(Application->ExeName) + "settings.ini", TEncoding::UTF8);
		Settings->WriteBool("Options", "RestartDaily", RestartCheck->Checked);
		Settings->WriteString("Options", "RestartHour", HourEdit->Text);
		Settings->WriteString("Options", "RestartMinute", MinEdit->Text);
		Settings->WriteString("Options", "Interval", IntEdit->Text);
		Settings->WriteString("Options", "DownCount", DownEdit->Text);
		Settings->WriteBool("Options", "AutoStartMon", AutostartCheck->Checked);
		Settings->WriteBool("Options", "Minimized", HideCheck->Checked);
		Settings->WriteBool("Options", "Logging", LogCheck->Checked);
		Settings->WriteBool("Options", "AutoRun", AutorunCheck->Checked);
		Settings->UpdateFile();
		delete Settings;

		// автозапуск
		if (AutorunCheck->Checked) AddToStartup();
		else RemoveFromStartup();

		// блокировка элементов формы
		IntEdit->Enabled = false;
		DownEdit->Enabled = false;
		RestartCheck->Enabled = false;
		HourEdit->Enabled = false;
		MinEdit->Enabled = false;
		AutostartCheck->Enabled = false;
		HideCheck->Enabled = false;
		AddButton->Enabled = false;
		AutorunCheck->Enabled = false;
		LogCheck->Enabled = false;
		Timer->Interval = StrToInt(IntEdit->Text) * 1000;

		// загрузка данных серверов
		if (FileExists(serversFile)) {
			TStringList *fileContent = new TStringList;
			try {
				fileContent->LoadFromFile(serversFile);
				String jsonData = fileContent->Text;
				serversArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
			}
			__finally {
				delete fileContent;
			}
		} else {
			Application->MessageBox(L"Отсутствует файл servers.json!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			return;
		}

		// запуск таймеров
		Timer->Enabled = true;
		MonitoringStarted = true;
		if (RestartCheck->Checked) {
			RestartTimer->Enabled = true;
		}
		TimerTimer(Timer);
		StartButton->Caption = "Остановить мониторинг";
		if (LogCheck->Checked) {
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Мониторинг запущен.\n").c_str());
			fclose(logFile);
		}
	} else {
		// разблокировка элементов формы
		IntEdit->Enabled = true;
		DownEdit->Enabled = true;
		RestartCheck->Enabled = true;
		if (RestartCheck->Checked) {
			HourEdit->Enabled = true;
			MinEdit->Enabled = true;
		}
		AutostartCheck->Enabled = true;
		HideCheck->Enabled = true;
		AddButton->Enabled = true;
		AutorunCheck->Enabled = true;
		LogCheck->Enabled = true;

		// остановка таймеров
		Timer->Enabled = false;
		RestartTimer->Enabled = false;
		MonitoringStarted = false;
		StartButton->Caption = "Начать мониторинг";
		if (LogCheck->Checked) {
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName)+"log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Мониторинг остановлен.\n").c_str());
			fclose(logFile);
		}

		for (int i = 0; i < Servers->Items->Count; i++) {
			TListItem *item = Servers->Items->Item[i];
			item->Caption = "";
			item->SubItems->Strings[2] = "";
			item->SubItems->Strings[3] = "";
		}
	}
}
//---------------------------------------------------------------------------

__fastcall TMonitoringThread::TMonitoringThread(bool CreateSuspended): TThread(CreateSuspended)
{
	FreeOnTerminate = true;
}

void __fastcall TMonitoringThread::Execute()
{
	String onl = L"\u2713";
	String off = L"\u2715";
	String priv = L"\U0001F512";
	int requiredSubItems = MainForm->Servers->Columns->Count - 1;
	for (int i = 0; i < serversArray->Count; i++) {
		TJSONObject *server = static_cast<TJSONObject*>(serversArray->Get(i));
		String ip = server->GetValue("ip")->Value();
		String port = server->GetValue("port")->Value();
		String pass = server->GetValue("password")->Value();
		String exe = server->GetValue("exe")->Value();
		String args = server->GetValue("args")->Value();
		String serverAddr = ip + ":" + port;
		int DownCount = 0;
		TJSONValue *downCountValue = server->GetValue("down_count");
		if (downCountValue == nullptr) server->AddPair("down_count", 0);
		else DownCount = StrToInt(downCountValue->ToString());

		String result = MainForm->ExecuteSSQR("query " + ip + " " + port);
		if (Trim(result) != "error") {
			DownCount = 0;
			TJSONObject *jsonObject = static_cast<TJSONObject*>(TJSONObject::ParseJSONValue(result));
			if (jsonObject != nullptr) {
				String map = jsonObject->GetValue("map")->Value();
				String players = jsonObject->GetValue("players")->Value();
				String max_players = jsonObject->GetValue("max_players")->Value();
				String is_private = jsonObject->GetValue("password")->Value();

				TThread::Queue(nullptr, [this, i, map, players, max_players, is_private, priv, onl, requiredSubItems]() {
					if (i >= 0 && i < MainForm->Servers->Items->Count) {
						TListItem *item = MainForm->Servers->Items->Item[i];

						// заполняем SubItems, если не заполнены
						while (item->SubItems->Count < requiredSubItems) {
							item->SubItems->Add("");
						}
						if (is_private == "true") item->Caption = "    " + priv;
						else item->Caption = "    " + onl;
						item->SubItems->Strings[2] = map;
						item->SubItems->Strings[3] = players + "/" + max_players;
					}
				});
			}
		} else {
			DownCount++;
			TThread::Queue(nullptr, [this, i, off, requiredSubItems, ip, port, exe, args]() {
				if (i >= 0 && i < MainForm->Servers->Items->Count) {
					TListItem *item = MainForm->Servers->Items->Item[i];

					// заполняем SubItems, если не заполнены
					while (item->SubItems->Count < requiredSubItems) {
						item->SubItems->Add("");
					}

					item->Caption = "    " + off;
					item->SubItems->Strings[2] = "";
					item->SubItems->Strings[3] = "";
				}
			});

			if (MainForm->LogCheck->Checked) {
				logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
				fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер " + serverAddr + " недоступен. Потытка " + DownCount + "/" + MainForm->DownEdit->Text + ".\n").c_str());
				fclose(logFile);
			}

			if (DownCount == StrToInt(MainForm->DownEdit->Text)) {
				// убиваем процесс
				system(AnsiString("taskkill /IM " + ExtractFileName(exe) + " /F").c_str());
				if (MainForm->LogCheck->Checked) {
					logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
					fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер " + serverAddr + " перезапускается...\n").c_str());
					fclose(logFile);
				}

				// запускаем сервер
				if (MainForm->LogCheck->Checked) logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
				if (FileExists(exe)) {
					ShellExecute(NULL, L"open", exe.c_str(), args.c_str(), NULL, SW_SHOWNORMAL);
					if (logFile != nullptr) fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер " + serverAddr + " запущен.\n").c_str());
				} else {
					if (logFile != nullptr) fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Файл \"" + exe + "\" не найден!\n").c_str());
				}
				if (logFile != nullptr) fclose(logFile);

				DownCount = 0;
			}
		}

		// обновление DownCount в массиве
		server->RemovePair("down_count");
		server->AddPair("down_count", DownCount);
	}

	TThread::Queue(nullptr, [this]() {
		MainForm->UpdateInticator->Animate = false;
	});
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerTimer(TObject *Sender)
{
	if (serversArray != nullptr) {
		if (monitoringThread == nullptr || monitoringThread->Finished) {
			UpdateInticator->Animate = true;
			monitoringThread = new TMonitoringThread(true);
			monitoringThread->Start();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RestartCheckClick(TObject *Sender)
{
	if (RestartCheck->Checked) {
		HourEdit->Enabled = true;
		MinEdit->Enabled = true;
	}
	else {
		HourEdit->Enabled = false;
		MinEdit->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (MonitoringStarted == true && LogCheck->Checked) {
		logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
		fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Мониторинг прерван.\n").c_str());
		fclose(logFile);
	}

	// сохранение позиции формы в ini
	Settings = new TMemIniFile(ExtractFilePath(Application->ExeName) + "settings.ini", TEncoding::UTF8);
	Settings->WriteInteger("Position", "Top", MainForm->Top);
	Settings->WriteInteger("Position", "Left", MainForm->Left);
	Settings->UpdateFile();
	delete Settings;

	// удаление serversArray
	if (serversArray != nullptr) {
		delete serversArray;
		serversArray = nullptr;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddButtonClick(TObject *Sender)
{
    ServerAddForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AlexellLogoClick(TObject *Sender)
{
	AboutForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ServersMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (Button == mbRight && Servers->Selected != nullptr && !MonitoringStarted) {
		TPoint point = Servers->ClientToScreen(Point(X, Y));
		PopupMenu->Popup(point.x, point.y);
	}
}
//---------------------------------------------------------------------------

bool IsProcessRunning(const wchar_t *processName)
{
    bool exists = false;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(hSnapshot, &pe)) {
            do {
                if (wcscmp(pe.szExeFile, processName) == 0) {
                    exists = true;
                    break;
				}
			} while (Process32Next(hSnapshot, &pe));
		}

		CloseHandle(hSnapshot);
	}

	return exists;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PMenuRestartClick(TObject *Sender)
{
	RestartSelectedServer(false);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PMenuShutdownClick(TObject *Sender)
{
	RestartSelectedServer(true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PMenuRemoveClick(TObject *Sender)
{
	TStringList *fileContent = new TStringList;
	try {
		fileContent->LoadFromFile(serversFile);
		String jsonData = fileContent->Text;
		TJSONArray *jsonArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
		if (jsonArray != nullptr) {
			int selectedIndex = Servers->Selected->Index;
			if (selectedIndex >= 0 && selectedIndex < jsonArray->Count) jsonArray->Remove(selectedIndex);
			if (jsonArray->Count > 0) {
				fileContent->Text = jsonArray->ToString();
				fileContent->SaveToFile(serversFile);
			} else DeleteFile(serversFile);
		}
		delete jsonArray;
	}
	__finally {
		delete fileContent;
	}
	LoadServers();
}
//---------------------------------------------------------------------------

String __fastcall TMainForm::ExecuteSSQR(const String &command)
{
    SECURITY_ATTRIBUTES sa;
    HANDLE hRead, hWrite;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;

	// создаем анонимный канал
    if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
		return false;
	}
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags |= STARTF_USESHOWWINDOW; // указываем, что используем wShowWindow
	si.wShowWindow = SW_HIDE; // скрываем окно
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;
	si.dwFlags |= STARTF_USESTDHANDLES;

	// запускаем процесс
	String exe = "ssqr.exe ";
	if (!CreateProcess(NULL, (exe + command).c_str(), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
		CloseHandle(hRead);
		CloseHandle(hWrite);
		return false;
	}
	CloseHandle(hWrite);

	// читаем вывод
	DWORD dwRead;
	CHAR chBuf[4096];
	String result;
	while (true) {
		if (!ReadFile(hRead, chBuf, sizeof(chBuf), &dwRead, NULL) || dwRead == 0) break;
		result += String(chBuf, dwRead);
	}
    CloseHandle(hRead);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return result;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RestartSelectedServer(bool shutdown) {
	TStringList *fileContent = new TStringList;
	try {
		fileContent->LoadFromFile(serversFile);
		String jsonData = fileContent->Text;

		TJSONArray *jsonArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
		if (jsonArray != nullptr) {
			int selectedIndex = Servers->Selected->Index;
			if (selectedIndex >= 0 && selectedIndex < jsonArray->Count) {
				TJSONObject *server = static_cast<TJSONObject*>(jsonArray->Get(selectedIndex));
				String ip = server->GetValue("ip")->Value();
				String port = server->GetValue("port")->Value();
				String pass = server->GetValue("password")->Value();
				String exe = server->GetValue("exe")->Value();
				String args = server->GetValue("args")->Value();
				String serverAddr = ip + ":" + port;

				if (pass == "") {
					Application->MessageBox(L"Не указан RCON пароль сервера!", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
					return;
				}
				String result = ExecuteSSQR("rcon " + ip + " " + port + " \"_restart\" \""+ pass + "\"");
				if (Trim(result) == "error") {
					Application->MessageBox(L"Не удалось выполнить RCON команду!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
					return;
				}
				if (shutdown) {
					if (LogCheck->Checked) {
						logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
						fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер " + serverAddr + " выключен пользователем.\n").c_str());
						fclose(logFile);
					}
				} else {
					Sleep(3000);
					String exeName = ExtractFileName(exe);
					if (!IsProcessRunning(exeName.w_str())) {
						if (FileExists(exe)) {
							ShellExecute(NULL, L"open", exe.c_str(), args.c_str(), NULL, SW_SHOWNORMAL);
							if (LogCheck->Checked) {
								logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
								fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер " + serverAddr + " перезапущен пользователем.\n").c_str());
								fclose(logFile);
							}
						} else Application->MessageBox(("Файл \"" + exe + "\" не найден!").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
					}
				}
			}
		}
		delete jsonArray;
	}
	__finally {
		delete fileContent;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PMenuEditClick(TObject *Sender)
{
	ServerAddForm->EditServer = true;
	ServerAddForm->EditServerID = Servers->Selected->Index;
	ServerAddForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RestartTimerTimer(TObject *Sender)
{
	// ежедневное выключение серверов
	CurDate = FormatDateTime("dd.mm.yyyy", Now());
	if (CurDate != LastRestart) {
		String hr = FormatDateTime("hh", Time());
		String mn = FormatDateTime("nn", Time());
		if (hr == HourEdit->Text && mn == MinEdit->Text) {
			Timer->Enabled = false;
			RestartTimer->Enabled = false;
			for (int i = 0; i < serversArray->Count; i++) {
				TJSONObject *server = static_cast<TJSONObject*>(serversArray->Get(i));
				String ip = server->GetValue("ip")->Value();
				String port = server->GetValue("port")->Value();
				String pass = server->GetValue("password")->Value();
				String exe = server->GetValue("exe")->Value();
				String args = server->GetValue("args")->Value();
				String serverAddr = ip + ":" + port;

				// мягко выключаем или убиваем процесс
				String exeName = ExtractFileName(exe);
				if (LogCheck->Checked) logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
				if (IsProcessRunning(exeName.w_str())) {
					if (logFile != nullptr) fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Выключение сервера " + serverAddr + " по расписанию...\n").c_str());
					if (pass != "") {
						String result = ExecuteSSQR("rcon " + ip + " " + port + " \"_restart\" \""+ pass + "\"");
						if (Trim(result) == "error") {
							system(AnsiString("taskkill /IM " + exeName + " /F").c_str());
						}
					} else system(AnsiString("taskkill /IM " + exeName + " /F").c_str());
				} else {
					if (logFile != nullptr) fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер " + serverAddr + " не работает, выключение по расписанию не требуется.\n").c_str());
				}
				if (logFile != nullptr) fclose(logFile);
			}
			Timer->Enabled = true;
			RestartTimer->Enabled = true;
		}
	}
}
//---------------------------------------------------------------------------

