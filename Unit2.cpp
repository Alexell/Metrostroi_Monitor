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
    // отключаем влияние стиля на цвет шрифта
	ArgsMemo->StyleElements = ArgsMemo->StyleElements >> seFont;
}
//---------------------------------------------------------------------------

void __fastcall TServerAddForm::FormShow(TObject *Sender)
{
	if (EditServer && EditServerID >= 0) {
		ServerAddForm->Caption = "Изменить сервер";

		String serversFile = "servers.json";
		TStringList *fileContent = new TStringList;
		try {
			fileContent->LoadFromFile(serversFile);
			String jsonData = fileContent->Text;
			TJSONArray *jsonArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
			if (jsonArray != nullptr) {
				TJSONObject *server = static_cast<TJSONObject*>(jsonArray->Get(EditServerID));
				IPEdit->Text = server->GetValue("ip")->Value();
				PortEdit->Text = server->GetValue("port")->Value();
				PassEdit->Text = server->GetValue("password")->Value();
				FileEdit->Text = server->GetValue("exe")->Value();
				ArgsMemo->Text = server->GetValue("args")->Value();
                ArgsMemo->Font->Color = clBlack;
				fileContent->Text = jsonArray->ToString();
				fileContent->SaveToFile(serversFile);
			}
			delete jsonArray;
		}
		__finally {
			delete fileContent;
		}
	} else ServerAddForm->Caption = "Добавить сервер";
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
	if (FileExists(serversFile)) { // добавляем / изменяем сервер в json
		TStringList *fileContent = new TStringList;
		try {
			fileContent->LoadFromFile(serversFile);
			String jsonData = fileContent->Text;

			TJSONArray *jsonArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(jsonData));
			if (jsonArray != nullptr) {
				TJSONObject *serverData = new TJSONObject();
				serverData->AddPair("ip", IPEdit->Text);
				serverData->AddPair("port", PortEdit->Text);
				serverData->AddPair("password", PassEdit->Text);
				serverData->AddPair("exe", FileEdit->Text);
				serverData->AddPair("args", ArgsMemo->Text);

				if (EditServer && EditServerID >= 0 && EditServerID < jsonArray->Count) {
					TJSONArray *newArray = new TJSONArray();
					for (int i = 0; i < jsonArray->Count; i++) {
						if (i == EditServerID) newArray->Add(serverData);
						else {
							TJSONObject *originalServer = static_cast<TJSONObject*>(jsonArray->Get(i));
							newArray->Add(originalServer);
						}
					}
					fileContent->Text = newArray->ToString();
					fileContent->SaveToFile(serversFile);

				} else {
					// предотвращение дублирования
					String newAddr = IPEdit->Text + ":" + PortEdit->Text;
					String newExe = FileEdit->Text;
					String newExeName = ExtractFileName(newExe);
					for (int i = 0; i < jsonArray->Count; i++) {
						TJSONObject *originalServer = static_cast<TJSONObject*>(jsonArray->Get(i));
						String ip = originalServer->GetValue("ip")->Value();
						String port = originalServer->GetValue("port")->Value();
						String pass = originalServer->GetValue("password")->Value();
						String exe = originalServer->GetValue("exe")->Value();
						String args = originalServer->GetValue("args")->Value();
						String serverAddr = ip + ":" + port;
						String exeName = ExtractFileName(exe);

						if (newAddr == serverAddr) {
							Application->MessageBox(("Сервер " + newAddr + " уже есть в списке!").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
							return;
						}
						if (newExe == exe) {
							Application->MessageBox(("Исполняемый файл " + newExe + " уже есть в списке!").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
							return;
						}
						if (newExeName == exeName) {
							Application->MessageBox(("Исполняемый файл " + newExeName + " уже есть в списке!\nВ каждом сервере, который вы добавляете в мониторинг должны быть разные имена исполняемых файлов, например srcds1.exe, srcds2.exe и т.п.\n\nПожалуйста переименуйте их, после чего добавляйте в мониторинг.").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
							return;
						}
					}

					jsonArray->Add(serverData);
					fileContent->Text = jsonArray->ToString();
					fileContent->SaveToFile(serversFile);
				}
				delete jsonArray;
			}
		}
		__finally {
			delete fileContent;
		}
	} else { // создаем и сохраняем json с первым сервером
		TJSONArray *jsonArray = new TJSONArray();
		TJSONObject *serverData = new TJSONObject();

		serverData->AddPair("ip", IPEdit->Text);
		serverData->AddPair("port", PortEdit->Text);
		serverData->AddPair("password", PassEdit->Text);
		serverData->AddPair("exe", FileEdit->Text);
		serverData->AddPair("args", ArgsMemo->Text);

		// предотвращение дублирования
		String newAddr = IPEdit->Text + ":" + PortEdit->Text;
		String newExe = FileEdit->Text;
		String newExeName = ExtractFileName(newExe);
		for (int i = 0; i < jsonArray->Count; i++) {
			TJSONObject *originalServer = static_cast<TJSONObject*>(jsonArray->Get(i));
			String ip = originalServer->GetValue("ip")->Value();
			String port = originalServer->GetValue("port")->Value();
			String pass = originalServer->GetValue("password")->Value();
			String exe = originalServer->GetValue("exe")->Value();
			String args = originalServer->GetValue("args")->Value();
			String serverAddr = ip + ":" + port;
			String exeName = ExtractFileName(exe);

			if (newAddr == serverAddr) {
				Application->MessageBox(("Сервер " + newAddr + " уже есть в списке!").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
				return;
			}
			if (newExe == exe) {
				Application->MessageBox(("Исполняемый файл " + newExe + " уже есть в списке!").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
				return;
			}
			if (newExeName == exeName) {
				Application->MessageBox(("Исполняемый файл " + newExeName + " уже есть в списке!\nВ каждом сервере, который вы добавляете в мониторинг должны быть разные имена исполняемых файлов, например srcds1.exe, srcds2.exe и т.п.\n\nПожалуйста переименуйте их, после чего добавляйте в мониторинг.").w_str(), Application->Title.w_str(), MB_OK | MB_ICONERROR);
				return;
			}
		}

		jsonArray->Add(serverData);

		TStringList *fileContent = new TStringList;
		try {
			fileContent->Text = jsonArray->ToString();
			fileContent->SaveToFile(serversFile);
		}
		__finally {
			delete fileContent;
		}
		delete jsonArray;
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
	EditServer = false;
	EditServerID = -1;
	MainForm->LoadServers();
}
//---------------------------------------------------------------------------

