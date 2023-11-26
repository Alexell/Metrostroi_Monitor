//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <System.JSON.hpp>
#include <System.StrUtils.hpp>
#include <System.RegularExpressions.hpp>
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

void __fastcall TServerAddForm::ArgsMemoClick(TObject *Sender)
{
	// очистка поля командной строки при настройке
	if (ArgsMemo->Text.Pos("...")) {
		ArgsMemo->Text = "";
		ArgsMemo->Font->Color = clBlack;
	}
}
//---------------------------------------------------------------------------

bool IsValidIPAddress(const String &ipAddress)
{
    return TRegEx::Match(ipAddress, L"^(\\d{1,3}(\\.\\d{1,3}){3})$").Success;
}
//---------------------------------------------------------------------------

void __fastcall TServerAddForm::SaveButtonClick(TObject *Sender)
{
	if (IPEdit->Text == "" || PortEdit->Text == "" || FileEdit->Text == "" || ArgsMemo->Text == "" || ArgsMemo->Text.Pos("...")) {
		Application->MessageBox(L"Не заполнены настройки!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
		return;
	}
	if (!IsValidIPAddress(IPEdit->Text)) {
		Application->MessageBox(L"Неверно указан IP адрес!", Application->Title.w_str(), MB_OK | MB_ICONERROR);
		return;
	}
	ArgsMemo->Text = StringReplace(ArgsMemo->Text, " /wait", "", TReplaceFlags() << rfReplaceAll);

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
			newServer->AddPair("password", PassEdit->Text);
			newServer->AddPair("exe", FileEdit->Text);
			newServer->AddPair("args", ArgsMemo->Text);

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
		newServer->AddPair("password", PassEdit->Text);
		newServer->AddPair("exe", FileEdit->Text);
		newServer->AddPair("args", ArgsMemo->Text);

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
	MainForm->LoadServers();
	ServerAddForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TServerAddForm::CancelButtonClick(TObject *Sender)
{
	ServerAddForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TServerAddForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	IPEdit->Text = "";
	PortEdit->Text = "";
	FileEdit->Text = "";
	ArgsMemo->Text = "-console -port 27015 -tickrate 33 -game garrysmod +gamemode sandbox ...";
	ArgsMemo->Font->Color = clSilver;
	PassEdit->Text = "";
	MainForm->LoadServers();
}
//---------------------------------------------------------------------------

