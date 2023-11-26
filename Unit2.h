//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TServerAddForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *IPEdit;
	TLabeledEdit *PortEdit;
	TLabeledEdit *FileEdit;
	TButton *FileButton;
	TLabel *CmdLabel;
	TMemo *CmdMemo;
	TOpenDialog *OpenDialog;
	TButton *SaveButton;
	TButton *CancelButton;
	void __fastcall FileButtonClick(TObject *Sender);
	void __fastcall CmdMemoClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TServerAddForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServerAddForm *ServerAddForm;
//---------------------------------------------------------------------------
#endif
