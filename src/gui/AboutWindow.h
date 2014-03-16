/*
	PicoBlaze Simulator
	Copyright (c) 2014 Mike Szymaniak <sc0typl@gmail.com>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

	About program window
*/

#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#ifndef WX_PRECOMP
	//(*HeadersPCH(AboutWindow)
	#include <wx/sizer.h>
	#include <wx/button.h>
	#include <wx/panel.h>
	#include <wx/frame.h>
	#include <wx/stattext.h>
	#include <wx/statbmp.h>
	//*)
#endif
//(*Headers(AboutWindow)
//*)

class AboutWindow: public wxFrame
{
	public:

		AboutWindow(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~AboutWindow();

		//(*Declarations(AboutWindow)
		wxPanel* Panel1;
		wxButton* btnOk;
		wxStaticBitmap* txtLogo;
		wxStaticText* txtInfo;
		//*)

	protected:

		//(*Identifiers(AboutWindow)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(AboutWindow)
		void OnbtnOkClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
