//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TServerAddForm *ServerAddForm;
//---------------------------------------------------------------------------
__fastcall TServerAddForm::TServerAddForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TServerAddForm::FileButtonClick(TObject *Sender)
{
	if (OpenDialog->Execute()) FileEdit->Text = OpenDialog->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TServerAddForm::CmdMemoClick(TObject *Sender)
{
	// очистка поля командной строки при настройке
	if (CmdMemo->Text.Pos("...")) CmdMemo->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TServerAddForm::IPEditKeyPress(TObject *Sender, System::WideChar &Key)

{
	// фильтр для поля IP адреса
	if ((Key >= '0' && Key <= '9') || Key == '.' || Key == VK_BACK) {}
	else Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TServerAddForm::SaveButtonClick(TObject *Sender)
{
	if (IPEdit->Text == "" || PortEdit->Text == "" || FileEdit->Text == "" || CmdMemo->Text == "" || CmdMemo->Text.Pos("...")) {
		Application->MessageBox(L"Не заполнены настройки!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
		return;
	}
	if (CmdMemo->Text.SubString(0, 11) == "start /wait") CmdMemo->Text = StringReplace(CmdMemo->Text," /wait","",TReplaceFlags() << rfReplaceAll);
	if (CmdMemo->Text.SubString(0, 5) != "start") {
		Application->MessageBox(L"Командная строка должна начинаться со \"start\"!", Application->Title.w_str(), MB_OK | MB_ICONEXCLAMATION);
		return;
	}

    String serversFile = "servers.json";
	if (FileExists(serversFile)) { // добавляем новый сервер в json
		TStringList *fileContent = new TStringList;
		try {
			fileContent->LoadFromFile(serversFile);
			String jsonData = fileContent->Text;

			TJSONArray *jsonArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
			if (jsonArray == nullptr) {
				jsonArray = new TJSONArray();
			}

			TJSONObject *newServer = new TJSONObject();
			newServer->AddPair("ip", IPEdit->Text);
			newServer->AddPair("port", PortEdit->Text);
			newServer->AddPair("exe", FileEdit->Text);
            newServer->AddPair("cmd", CmdMemo->Text);

			jsonArray->Add(newServer);

			fileContent->Text = jsonArray->ToString();
			fileContent->SaveToFile(serversFile);

			delete jsonArray;
		}
		__finally {
			delete fileContent;
		}
	} else { // создаем и сохраняем json с первым сервером
		TJSONArray *jsonArray = new TJSONArray();
		TJSONObject *newServer = new TJSONObject();
		newServer->AddPair("ip", IPEdit->Text);
		newServer->AddPair("port", PortEdit->Text);
		newServer->AddPair("exe", FileEdit->Text);
		newServer->AddPair("cmd", CmdMemo->Text);

		jsonArray->Add(newServer);

		TStringList *fileContent = new TStringList;
		try {
			fileContent->Text = jsonArray->ToString();
			fileContent->SaveToFile(serversFile);

			delete jsonArray;
		}
		__finally {
			delete fileContent;
		}
	}
	IPEdit->Text = "";
	PortEdit->Text = "";
	FileEdit->Text = "";
	CmdMemo->Text = "start srcds.exe -console -port 27017 -tickrate 33 -game ...";
	MainForm->LoadServers();
	ServerAddForm->Close();
}
//---------------------------------------------------------------------------

