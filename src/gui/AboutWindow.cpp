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

#include "src/wx_pch.h"
#include "AboutWindow.h"

#ifndef WX_PRECOMP
	//(*InternalHeadersPCH(AboutWindow)
	#include <wx/string.h>
	#include <wx/intl.h>
	//*)
#endif
//(*InternalHeaders(AboutWindow)
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(AboutWindow)
const long AboutWindow::ID_STATICBITMAP1 = wxNewId();
const long AboutWindow::ID_STATICTEXT1 = wxNewId();
const long AboutWindow::ID_BUTTON1 = wxNewId();
const long AboutWindow::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AboutWindow,wxFrame)
	//(*EventTable(AboutWindow)
	//*)
END_EVENT_TABLE()

AboutWindow::AboutWindow(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(AboutWindow)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, _("About program"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxFRAME_TOOL_WINDOW|wxFRAME_FLOAT_ON_PARENT, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	txtLogo = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("img/logo.png")).Rescale(wxSize(160,160).GetWidth(),wxSize(160,160).GetHeight())), wxDefaultPosition, wxSize(160,160), 0, _T("ID_STATICBITMAP1"));
	FlexGridSizer2->Add(txtLogo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
	txtInfo = new wxStaticText(Panel1, ID_STATICTEXT1, _("PicoBlaze Simulator\n\nApplication developed during work on BSc thesis\nat Poznan University of Technology in 2013.\nRelesed under GNU GPL license.\n\nAuthor: Mike Szymaniak\nhttp://sc0ty.pl\nsc0typl@gmail.com"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	wxFont txtInfoFont(10,wxDEFAULT,wxFONTSTYLE_NORMAL,wxNORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	txtInfo->SetFont(txtInfoFont);
	FlexGridSizer2->Add(txtInfo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnOk = new wxButton(Panel1, ID_BUTTON1, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	btnOk->SetDefault();
	FlexGridSizer1->Add(btnOk, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
	Panel1->SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(Panel1);
	FlexGridSizer1->SetSizeHints(Panel1);
	BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AboutWindow::OnbtnOkClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&AboutWindow::OnClose);
	//*)
}

AboutWindow::~AboutWindow()
{
	//(*Destroy(AboutWindow)
	//*)
}


void AboutWindow::OnbtnOkClick(wxCommandEvent& event)
{
    Close();
}

void AboutWindow::OnClose(wxCloseEvent& event)
{
    MakeModal(false);
    event.Skip();
}
