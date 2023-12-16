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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *IntEdit;
	TCheckBox *RestartCheck;
	TEdit *HourEdit;
	TEdit *MinEdit;
	TLabel *SeparatorLabel;
	TCheckBox *AutostartCheck;
	TCheckBox *HideCheck;
	TButton *StartButton;
	TTimer *Timer;
	TIdAntiFreeze *IdAntiFreeze;
	TTrayIcon *Tray;
	TListView *Servers;
	TButton *AddButton;
	TLabeledEdit *DownEdit;
	TActivityIndicator *UpdateInticator;
	TImage *AlexellLogo;
	TPopupMenu *PopupMenu;
	TMenuItem *PMenuRestart;
	TMenuItem *PMenuRemove;
	TMenuItem *PMenuShutdown;
	TMenuItem *PMenuEdit;
	TTimer *RestartTimer;
	TCheckBox *AutorunCheck;
	TCheckBox *LogCheck;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall StartButtonClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall RestartCheckClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall AlexellLogoClick(TObject *Sender);
	void __fastcall ServersMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PMenuRemoveClick(TObject *Sender);
	void __fastcall PMenuRestartClick(TObject *Sender);
	void __fastcall PMenuShutdownClick(TObject *Sender);
	void __fastcall PMenuEditClick(TObject *Sender);
	void __fastcall RestartTimerTimer(TObject *Sender);
	void __fastcall PopupMenuPopup(TObject *Sender);

private:	// User declarations
	void __fastcall RestartSelectedServer(bool shutdown);
public:		// User declarations
	void __fastcall LoadServers();
	String __fastcall ExecuteSSQR(const String &command);
	__fastcall TMainForm(TComponent* Owner);
};

// класс потока мониторинга
class TMonitoringThread : public TThread
{
protected:
	void __fastcall Execute();

public:
	__fastcall TMonitoringThread(bool CreateSuspended);
};

// класс потока рестарта
class TRestartThread : public TThread
{
protected:
	void __fastcall Execute();

public:
	__fastcall TRestartThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
