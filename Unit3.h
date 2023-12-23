//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *AuthorTitle;
	TLabel *WebsiteTitle;
	TLabel *ProjectTitle;
	TLabel *AuthorLabel;
	TLabel *AlexellLink;
	TLabel *VersionTitle;
	TLabel *VersionLabel;
	TLabel *MSSLink;
	TImage *MSSLogo;
	TButton *CloseButton;
	TPanel *Hr;
	TLabel *GitHubLink;
	void __fastcall AlexellLinkClick(TObject *Sender);
	void __fastcall MSSLinkClick(TObject *Sender);
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall GitHubLinkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
