#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(AboutDialog)
	#include <wx/sizer.h>
	#include <wx/button.h>
	#include <wx/panel.h>
	#include <wx/frame.h>
	#include <wx/stattext.h>
	#include <wx/statbmp.h>
	//*)
#endif
//(*Headers(AboutDialog)
//*)

class AboutDialog: public wxDialog
{
	public:

		AboutDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AboutDialog();

		//(*Declarations(AboutDialog)
		wxPanel* Panel1;
		wxButton* btnOk;
		wxStaticBitmap* txtLogo;
		wxStaticText* txtInfo;
		//*)

	protected:

		//(*Identifiers(AboutDialog)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(AboutDialog)
		void OnbtnOkClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
