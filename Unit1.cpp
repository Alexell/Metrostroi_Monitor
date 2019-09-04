//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IniFiles.hpp"
//#include <stdlib.h>
#include <Tlhelp32.h>
//#include <fstream.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TMemIniFile* Settings;
int pid;
bool started = false;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	MainForm->Caption=Application->Title;

    //Загружаем настройки из INI файла
	if (FileExists(ExtractFilePath(Application->ExeName)+"settings.ini"))
	{
		Settings = new TMemIniFile(ExtractFilePath(Application->ExeName)+"settings.ini",TEncoding::UTF8);
		IPEdit->Text = Settings->ReadString("Server","IP","");
		PortEdit->Text = Settings->ReadString("Server","Port","");
		FileEdit->Text = Settings->ReadString("Server","Exe","");
		CmdMemo->Text = Settings->ReadString("Server","Cmd","");
		IntEdit->Text = Settings->ReadString("Options","Interval","");
		AutostartCheck->State=Settings->ReadBool("Options","Autostart",0);
		HideCheck->State=Settings->ReadBool("Options","Minimized",0);
		delete Settings;
		Timer->Interval=StrToInt(IntEdit->Text)*1000;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	AboutLabel->Caption = "Автор: Alexell | Сайт: alexell.ru";
	if(HideCheck->Checked)
	{
		Application->Minimize();
	}
	if(AutostartCheck->Checked)
	{
		StartButton->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileButtonClick(TObject *Sender)
{
	if(OpenDialog->Execute())
	{
		if (ExtractFileName(OpenDialog->FileName) != "srcds.exe")
		{
			Application->MessageBox(L"Указан неверный файл!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			return;
		}
		FileEdit->Text = OpenDialog->FileName;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::StartButtonClick(TObject *Sender)
{
	if (started == false)
	{
		//Обработка полей
		if (IntEdit->Text == "" || FileEdit->Text == "" || CmdMemo->Text == "" || CmdMemo->Text.Pos("..."))
		{
			Application->MessageBox(L"Не заполнены настройки!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			return;
		}
		if (StrToInt(IntEdit->Text)<60)
		{
			Application->MessageBox(L"Минимальный интервал мониторинга: 60 секунд.", Application->Title.w_str(), MB_OK | MB_ICONERROR);
			IntEdit->Text = "60";
			return;
		}
		if(CmdMemo->Text.SubString(0,9) != "srcds.exe")
		{
			Application->MessageBox(L"Командная строка должна начинаться с \"srcds.exe\"!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
            CmdMemo->Text = "srcds.exe " + CmdMemo->Text;
			return;
		}

		//Сохранение настроек в INI
		Settings = new TMemIniFile(ExtractFilePath(Application->ExeName)+"settings.ini",TEncoding::UTF8);
		Settings->WriteString("Server","IP",IPEdit->Text);
		Settings->WriteString("Server","Port",PortEdit->Text);
		Settings->WriteString("Server","Exe",FileEdit->Text);
		Settings->WriteString("Server","Cmd",CmdMemo->Text);
		Settings->WriteString("Options","Interval",IntEdit->Text);
		Settings->WriteBool("Options","Autostart",AutostartCheck->State);
		Settings->WriteBool("Options","Minimized",HideCheck->State);
		Settings->UpdateFile();
		delete Settings;

		//Блокировка элементов формы
		IPEdit->Enabled = false;
		PortEdit->Enabled = false;
		FileEdit->Enabled = false;
		FileButton->Enabled = false;
		CmdMemo->Enabled = false;
		IntEdit->Enabled = false;
		AutostartCheck->Enabled = false;
		HideCheck->Enabled = false;
		Timer->Interval=StrToInt(IntEdit->Text)*1000;
		IdTCPClient->Host=IPEdit->Text;
		IdTCPClient->Port=StrToInt(PortEdit->Text);

		//Запуск таймера
		Timer->Enabled = true;
		started = true;
		StartButton->Caption = "Остановить мониторинг";
	}
	else
	{
		//Разблокировка элементов формы
		IPEdit->Enabled = true;
		PortEdit->Enabled = true;
		FileEdit->Enabled = true;
		FileButton->Enabled = true;
		CmdMemo->Enabled = true;
		IntEdit->Enabled = true;
		AutostartCheck->Enabled = true;
		HideCheck->Enabled = true;
		StartButton->Enabled = true;

		//Остановка таймера
		Timer->Enabled = false;
		started = false;
		StartButton->Caption = "Начать мониторинг";
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerTimer(TObject *Sender)
{
	//Мониторинг доступности IP:Port
	char *cmd;
	Timer->Enabled = false;
	try
	{
		IdTCPClient->Connect();
	}
	catch(...) //если порт недоступен
	{
		//Проверяем наличие процесса + kill
        pid = 0;
		cmd = AnsiString(ExtractFileName(FileEdit->Text)).c_str();
		pid = IsProcessRunning(cmd);
		if (pid != 0)
		{
			KillProcess(pid);
		}

		//Запускаем сервер
		SetCurrentDir(ExtractFileDir(FileEdit->Text));
		cmd = AnsiString(ExtractFileName(FileEdit->Text)+" "+CmdMemo->Text).c_str();
		WinExec(cmd,SW_SHOW);
	}
	if(IdTCPClient->Connected()) //если порт доступен
	{
		IdTCPClient->Disconnect();
	}
	Timer->Enabled = true;
}
//---------------------------------------------------------------------------

int TMainForm::IsProcessRunning( char * pName )
{
	int id_p;
	strlwr( pName );
	HANDLE snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
	PROCESSENTRY32 pe;
	char pExeName[256];
	for( BOOL r=Process32First(snapshot, &pe); r; r=Process32Next(snapshot, &pe) )
	{
		if( strcmp( pe.szExeFile, pName ) == 0 )
		{
			id_p=pe.th32ProcessID;
			CloseHandle(snapshot);
			return id_p;
		}
	}
	CloseHandle(snapshot);
	return 0;
}
//---------------------------------------------------------------------------

void TMainForm::KillProcess(int id)
{
   HANDLE ps = OpenProcess(1, false, id);
   if (ps) TerminateProcess(ps, -9);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CmdMemoClick(TObject *Sender)
{
    //Очистка поля командной строки при первой настройке
	if (CmdMemo->Text.Pos("..."))
	{
        CmdMemo->Text = "";
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::IPEditKeyPress(TObject *Sender, System::WideChar &Key)
{
    //Фильтр для поля IP адреса
	if((Key >= '0') && (Key <= '9') || Key == '.' || Key == VK_BACK){}
	else Key = 0;
}
//---------------------------------------------------------------------------

