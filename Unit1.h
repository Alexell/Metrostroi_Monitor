//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <Vcl.AppEvnts.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *IPEdit;
	TLabeledEdit *PortEdit;
	TLabeledEdit *IntEdit;
	TCheckBox *HideCheck;
	TLabeledEdit *FileEdit;
	TOpenDialog *OpenDialog;
	TButton *FileButton;
	TTimer *Timer;
	TButton *StartButton;
	TIdTCPClient *IdTCPClient;
	TIdAntiFreeze *IdAntiFreeze;
	TMemo *CmdMemo;
	TLabel *CmdLabel;
	TCheckBox *AutostartCheck;
	TTrayIcon *Tray;
	TLabel *AboutLabel;
	TLabel *ActionLabel;
	TButton *LogButton;
	TCheckBox *RestartCheck;
	TEdit *HourEdit;
	TEdit *MinEdit;
	TLabel *SeparatorLabel;
	void __fastcall FileButtonClick(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CmdMemoClick(TObject *Sender);
	void __fastcall IPEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall LogButtonClick(TObject *Sender);
	void __fastcall RestartCheckClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
