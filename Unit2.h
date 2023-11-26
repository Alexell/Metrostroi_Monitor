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
	TLabel *ArgsLabel;
	TMemo *ArgsMemo;
	TOpenDialog *OpenDialog;
	TButton *SaveButton;
	TButton *CancelButton;
	TLabeledEdit *PassEdit;
	TLabel *RconNote;
	void __fastcall FileButtonClick(TObject *Sender);
	void __fastcall ArgsMemoClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TServerAddForm(TComponent* Owner);
	bool EditServer;
	int EditServerID;
};
//---------------------------------------------------------------------------
extern PACKAGE TServerAddForm *ServerAddForm;
//---------------------------------------------------------------------------
#endif
