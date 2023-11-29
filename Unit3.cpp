//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::AlexellLinkClick(TObject *Sender)
{
	ShellExecute(NULL, L"open", L"https://alexell.ru", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::MSSLinkClick(TObject *Sender)
{
    ShellExecute(NULL, L"open", L"https://mss-project.org", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::CloseButtonClick(TObject *Sender)
{
    AboutForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::GitHubLinkClick(TObject *Sender)
{
    ShellExecute(NULL, L"open", L"https://github.com/Alexell/Metrostroi_Monitor", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

