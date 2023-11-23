//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IniFiles.hpp"
#include "SSQ.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TMemIniFile* Settings;
int pid;
int DownCount = 0;
bool started = false;
String CurDate,LastRestart;
FILE *logFile;
HINSTANCE dllhandle;
typedef BOOL (WINAPI *SSQ_InitializeFuncType)(BOOL exit);
typedef BOOL (WINAPI *SSQ_SetTimeoutFuncType)(DWORD type, int timeout);
typedef BOOL (WINAPI *SSQ_SetGameServerFuncType)(char* address);
typedef BOOL (WINAPI *SSQ_GetInfoReplyFuncType)(PSSQ_INFO_REPLY info_reply);
SSQ_InitializeFuncType SSQ_InitializeFunc = nullptr;
SSQ_SetTimeoutFuncType SSQ_SetTimeoutFunc = nullptr;
SSQ_SetGameServerFuncType SSQ_SetGameServerFunc = nullptr;
SSQ_GetInfoReplyFuncType SSQ_GetInfoReplyFunc = nullptr;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	MainForm->Caption=Application->Title;

    //Загружаем настройки из INI файла
	if (FileExists(ExtractFilePath(Application->ExeName)+"settings.ini"))
	{
		Settings = new TMemIniFile(ExtractFilePath(Application->ExeName) + "settings.ini", TEncoding::UTF8);
		IPEdit->Text = Settings->ReadString("Server", "IP", "");
		PortEdit->Text = Settings->ReadString("Server", "Port", "27015");
		FileEdit->Text = Settings->ReadString("Server", "Exe", "");
		CmdMemo->Text = Settings->ReadString("Server", "Cmd", "");
		RestartCheck->Checked = Settings->ReadBool("Options", "RestartDaily", 0);
		HourEdit->Text = Settings->ReadString("Options", "RestartHour", "04");
		MinEdit->Text = Settings->ReadString("Options", "RestartMinute", "00");
		IntEdit->Text = Settings->ReadString("Options", "Interval", "");
		AutostartCheck->Checked = Settings->ReadBool("Options", "Autostart", 0);
		HideCheck->Checked = Settings->ReadBool("Options", "Minimized", 0);
		delete Settings;
		Timer->Interval = StrToInt(IntEdit->Text) * 1000;
	}
	// Загружаем SourceQuery DLL
	dllhandle = LoadLibraryA("SSQ.dll");
	if (!dllhandle) {
		Application->MessageBox(L"SSQ.dll не найден!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
		Application->Terminate();
	}

	SSQ_InitializeFunc = (SSQ_InitializeFuncType)GetProcAddress(dllhandle, "SSQ_Initialize");
	SSQ_SetTimeoutFunc = (SSQ_SetTimeoutFuncType)GetProcAddress(dllhandle, "SSQ_SetTimeout");
	SSQ_SetGameServerFunc = (SSQ_SetGameServerFuncType)GetProcAddress(dllhandle, "SSQ_SetGameServer");
	SSQ_GetInfoReplyFunc = (SSQ_GetInfoReplyFuncType)GetProcAddress(dllhandle, "SSQ_GetInfoReply");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormShow(TObject *Sender)
{
	AboutLabel->Caption = "Автор: Alexell | Сайт: alexell.ru";
	if (HideCheck->Checked) Application->Minimize();
	if (AutostartCheck->Checked) StartButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileButtonClick(TObject *Sender)
{
    if (OpenDialog->Execute()) FileEdit->Text = OpenDialog->FileName;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::StartButtonClick(TObject *Sender)
{
	if (started == false) {
		//Обработка полей
		if (IntEdit->Text == "" || FileEdit->Text == "" || CmdMemo->Text == "" || CmdMemo->Text.Pos("...")) {
			Application->MessageBox(L"Не заполнены настройки!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			return;
		}
		if (StrToInt(IntEdit->Text) < 30) {
			Application->MessageBox(L"Минимальный интервал мониторинга: 30 секунд.", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
			IntEdit->Text = "30";
			return;
		}
		if (CmdMemo->Text.SubString(0, 11) == "start /wait") CmdMemo->Text = StringReplace(CmdMemo->Text," /wait","",TReplaceFlags() << rfReplaceAll);
		if (CmdMemo->Text.SubString(0, 5) != "start") {
			Application->MessageBox(L"Командная строка должна начинаться со \"start\"!", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
			return;
		}
		if (RestartCheck->Checked) {
			if (StrToInt(HourEdit->Text) > 23 || StrToInt(MinEdit->Text) > 59) {
				Application->MessageBox(L"Неверное время перезапуска сервера.", Application->Title.w_str(), MB_OK | MB_ICONERROR);
				HourEdit->Text = "00";
				MinEdit->Text = "00";
				return;
			}
		}

		//Сохранение настроек в INI
		Settings = new TMemIniFile(ExtractFilePath(Application->ExeName) + "settings.ini", TEncoding::UTF8);
		Settings->WriteString("Server", "IP", IPEdit->Text);
		Settings->WriteString("Server", "Port", PortEdit->Text);
		Settings->WriteString("Server", "Exe", FileEdit->Text);
		Settings->WriteString("Server", "Cmd", CmdMemo->Text);
		Settings->WriteBool("Options", "RestartDaily", RestartCheck->Checked);
		Settings->WriteString("Options", "RestartHour", HourEdit->Text);
		Settings->WriteString("Options", "RestartMinute", MinEdit->Text);
		Settings->WriteString("Options", "Interval", IntEdit->Text);
		Settings->WriteBool("Options", "Autostart", AutostartCheck->Checked);
		Settings->WriteBool("Options", "Minimized", HideCheck->Checked);
		Settings->UpdateFile();
		delete Settings;

		//Блокировка элементов формы
		IPEdit->Enabled = false;
		PortEdit->Enabled = false;
		FileEdit->Enabled = false;
		FileButton->Enabled = false;
		CmdMemo->Enabled = false;
		IntEdit->Enabled = false;
		RestartCheck->Enabled = false;
		HourEdit->Enabled = false;
		MinEdit->Enabled = false;
		AutostartCheck->Enabled = false;
		HideCheck->Enabled = false;
		Timer->Interval = StrToInt(IntEdit->Text) * 1000;
		IdTCPClient->Host = IPEdit->Text;
		IdTCPClient->Port = StrToInt(PortEdit->Text);

		//Запуск таймера
		Timer->Enabled = true;
		started = true;
		StartButton->Caption = "Остановить мониторинг";
		logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
		fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Мониторинг запущен.\n").c_str());
		fclose(logFile);
	} else {
		//Разблокировка элементов формы
		IPEdit->Enabled = true;
		PortEdit->Enabled = true;
		FileEdit->Enabled = true;
		FileButton->Enabled = true;
		CmdMemo->Enabled = true;
		IntEdit->Enabled = true;
		RestartCheck->Enabled = true;
		if (RestartCheck->Checked) {
			HourEdit->Enabled = true;
			MinEdit->Enabled = true;
		}
		AutostartCheck->Enabled = true;
		HideCheck->Enabled = true;
		StartButton->Enabled = true;

		//Остановка таймера
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
	char *cmd;
	Timer->Enabled = false;

	//Ежедневная перезагрузка сервера
	if (RestartCheck->Checked) {
		CurDate = FormatDateTime("dd.mm.yyyy", Now());
		if (CurDate != LastRestart) {
			String hr = FormatDateTime("hh", Time());
			String mn = FormatDateTime("nn", Time());
			if (hr == HourEdit->Text && mn == MinEdit->Text) {
				//Убиваем процесс
				system(AnsiString("taskkill /IM " + ExtractFileName(FileEdit->Text) + " /F").c_str());
				logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
				fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Перезапуск сервера по расписанию...\n").c_str());
				fclose(logFile);

				//Запускаем сервер
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
	// Мониторинг через SourceQuery
	SSQ_InitializeFunc(false);
	SSQ_SetTimeoutFunc(SSQ_GS_TIMEOUT, 1000);
	UnicodeString fullAddr = IPEdit->Text + ":" + PortEdit->Text;
	int bufLen = WideCharToMultiByte(CP_ACP, 0, fullAddr.c_str(), -1, NULL, 0, NULL, NULL);
	char *serverAddress = new char[bufLen];
	WideCharToMultiByte(CP_ACP, 0, fullAddr.c_str(), -1, serverAddress, bufLen, NULL, NULL);
	bool connectionSuccess = SSQ_SetGameServerFunc(serverAddress);
	PSSQ_INFO_REPLY reply = new SSQ_INFO_REPLY;
	if (connectionSuccess) { // подключение к серверу работает
		if (SSQ_GetInfoReplyFunc(reply)) { // получение информации не работает
			// вывод для отладки
			String logData;
			logData += "Hostname: " + String(reply->hostname) + "\n";
			logData += "Map: " + String(reply->map) + "\n";
			Application->MessageBox(logData.w_str(), Application->Title.w_str(), MB_OK | MB_ICONINFORMATION);
			// -----------------------
		}
	} else {
		DownCount++;
		if (DownCount == 3) {
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Порт " + PortEdit->Text + " недоступен.\n").c_str());
			fclose(logFile);

			//Убиваем процесс
			system(AnsiString("taskkill /IM " + ExtractFileName(FileEdit->Text) + " /F").c_str());
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер перезапускается...\n").c_str());
			fclose(logFile);

			//Запускаем сервер
			SetCurrentDir(ExtractFileDir(FileEdit->Text));
			cmd = AnsiString(ExtractFileName(FileEdit->Text) + " " + CmdMemo->Text).c_str();
			WinExec(cmd, SW_SHOW);
			logFile = fopen(AnsiString(ExtractFilePath(Application->ExeName) + "log.txt").c_str(), "a+");
			fprintf(logFile, "%s", AnsiString(FormatDateTime("dd.mm.yyyy hh:nn:ss", Now()) + " | Сервер запущен.\n").c_str());
			fclose(logFile);
			DownCount = 0;
		}
	}

	// освобождаем память
	delete[] serverAddress;
	delete reply;
	SSQ_InitializeFunc(true);

	DownCount = 0;
	Timer->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CmdMemoClick(TObject *Sender)
{
    //Очистка поля командной строки при первой настройке
	if (CmdMemo->Text.Pos("...")) CmdMemo->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IPEditKeyPress(TObject *Sender, System::WideChar &Key)

{
    //Фильтр для поля IP адреса
	if ((Key >= '0' && Key <= '9') || Key == '.' || Key == VK_BACK) {}
	else Key = 0;
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
}
//---------------------------------------------------------------------------

