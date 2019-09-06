//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLogForm *LogForm;
//---------------------------------------------------------------------------
__fastcall TLogForm::TLogForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLogForm::FormHide(TObject *Sender)
{
	Position = poMainFormCenter;
}
//---------------------------------------------------------------------------

void __fastcall TLogForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    Hide();
    Position = poMainFormCenter;
}
//---------------------------------------------------------------------------

