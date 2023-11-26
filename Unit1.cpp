//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "IniFiles.hpp"
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TMemIniFile* Settings;
String serversFile = "servers.json";
int DownCount = 0;
bool started = false;
String CurDate,LastRestart;
FILE *logFile;
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
		AutostartCheck->Checked = Settings->ReadBool("Options", "Autostart", 0);
		HideCheck->Checked = Settings->ReadBool("Options", "Minimized", 0);
		MainForm->Top = Settings->ReadInteger("Position", "Top", 0);
		MainForm->Left = Settings->ReadInteger("Position", "Left", 0);
		delete Settings;
		Timer->Interval = StrToInt(IntEdit->Text) * 1000;
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
					item->Caption = ip;
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

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (HideCheck->Checked) Application->Minimize();
	if (AutostartCheck->Checked) StartButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StartButtonClick(TObject *Sender)
{
	if (started == false) {
		if (Servers->Items->Count == 0) {
			Application->MessageBox(L"Сервера для мониторинга отсутствуют!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			return;
		}
		if (StrToInt(IntEdit->Text) < 30) {
			Application->MessageBox(L"Минимальный интервал мониторинга: 30 секунд", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
			IntEdit->Text = "30";
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
		Settings->WriteBool("Options", "Autostart", AutostartCheck->Checked);
		Settings->WriteBool("Options", "Minimized", HideCheck->Checked);
		Settings->UpdateFile();
		delete Settings;

		// блокировка элементов формы
		IntEdit->Enabled = false;
		DownEdit->Enabled = false;
		RestartCheck->Enabled = false;
		HourEdit->Enabled = false;
		MinEdit->Enabled = false;
		AutostartCheck->Enabled = false;
		HideCheck->Enabled = false;
		AddButton->Enabled = false;
		Timer->Interval = StrToInt(IntEdit->Text) * 1000;

		// запуск таймера
		Timer->Enabled = true;
		started = true;
		StartButton->Caption = "Остановить мониторинг";
		logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
		fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Мониторинг запущен.\n").c_str());
		fclose(logFile);
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

		// остановка таймера
		Timer->Enabled = false;
		started = false;
		StartButton->Caption = "Начать мониторинг";
		logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName)+"log.txt").c_str(), "a+");
		fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Мониторинг остановлен.\n").c_str());
		fclose(logFile);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerTimer(TObject *Sender)
{
	/*char *cmd;
	Timer->Enabled = false;

	// ежедневная перезагрузка сервера
	if (RestartCheck->Checked) {
		CurDate = FormatDateTime("dd.mm.yyyy", Now());
		if (CurDate != LastRestart) {
			String hr = FormatDateTime("hh", Time());
			String mn = FormatDateTime("nn", Time());
			if (hr == HourEdit->Text && mn == MinEdit->Text) {
				// убиваем процесс
				system(AnsiString("taskkill /IM " + ExtractFileName(FileEdit->Text) + " /F").c_str());
				logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
				fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Перезапуск сервера по расписанию...\n").c_str());
				fclose(logFile);

				// запускаем сервер
				SetCurrentDir(ExtractFileDir(FileEdit->Text));
				cmd = AnsiString(ExtractFileName(FileEdit->Text) + " " + CmdMemo->Text).c_str();
				WinExec(cmd, SW_SHOW);
				LastRestart = FormatDateTime("dd.mm.yyyy", Now());
				logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
				fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер запущен.\n").c_str());
				fclose(logFile);
				Timer->Enabled = true;
				return;
			}
		}
	}

	// мониторинг доступности IP:Port
	try {
		IdTCPClient->Connect();
		if (IdTCPClient->Connected()) { //если порт доступен
			IdTCPClient->Disconnect();
			DownCount = 0;
		}
	} catch(...) { // если порт недоступен
		DownCount++;
		if (DownCount == 3) {
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Порт " + PortEdit->Text + " недоступен.\n").c_str());
			fclose(logFile);

			// убиваем процесс
			system(AnsiString("taskkill /IM " + ExtractFileName(FileEdit->Text) + " /F").c_str());
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер перезапускается...\n").c_str());
			fclose(logFile);

			// запускаем сервер
			SetCurrentDir(ExtractFileDir(FileEdit->Text));
			cmd = AnsiString(ExtractFileName(FileEdit->Text) + " " + CmdMemo->Text).c_str();
			WinExec(cmd, SW_SHOW);
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер запущен.\n").c_str());
			fclose(logFile);
            DownCount = 0;
		}
	}
	Timer->Enabled = true;*/
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
	if (started == true) {
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
	if (Button == mbRight && Servers->Selected != nullptr) {
		TPoint point = Servers->ClientToScreen(Point(X, Y));
		PopupMenu->Popup(point.x, point.y);
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender)
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
				} else DeleteFile("servers.json");
			}
			delete jsonArray;
		}
		__finally {
			delete fileContent;
		}
		LoadServers();
}
//---------------------------------------------------------------------------

