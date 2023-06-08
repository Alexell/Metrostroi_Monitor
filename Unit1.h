//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *IPEdit;
	TLabeledEdit *PortEdit;
	TLabeledEdit *IntEdit;
	TLabeledEdit *FileEdit;
	TButton *FileButton;
	TLabel *CmdLabel;
	TMemo *CmdMemo;
	TCheckBox *RestartCheck;
	TEdit *HourEdit;
	TEdit *MinEdit;
	TLabel *SeparatorLabel;
	TLabel *ActionLabel;
	TCheckBox *AutostartCheck;
	TCheckBox *HideCheck;
	TButton *StartButton;
	TLabel *AboutLabel;
	TOpenDialog *OpenDialog;
	TIdTCPClient *IdTCPClient;
	TTimer *Timer;
	TIdAntiFreeze *IdAntiFreeze;
	TTrayIcon *Tray;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FileButtonClick(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall CmdMemoClick(TObject *Sender);
	void __fastcall IPEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall RestartCheckClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
