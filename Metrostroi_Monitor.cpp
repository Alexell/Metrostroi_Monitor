//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Unit2.cpp", ServerAddForm);
USEFORM("Unit1.cpp", MainForm);
USEFORM("Unit3.cpp", AboutForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Lavender Classico");
		Application->Title = "Metrostroi Monitor";
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TServerAddForm), &ServerAddForm);
		Application->CreateForm(__classid(TAboutForm), &AboutForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
