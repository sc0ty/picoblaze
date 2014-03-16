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

	Device window - switches
*/

#ifndef SWITCHWINDOW_H
#define SWITCHWINDOW_H

#ifndef WX_PRECOMP
//(*HeadersPCH(SwitchWindow)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)
#endif
//(*Headers(SwitchWindow)
#include <wx/statline.h>
//*)

#include "../../cpu/cpu.h"
#include "../MainWindow.h"

class SwitchWindow: public wxFrame
{
public:

    SwitchWindow(
        MainWindow* parent,
        Cpu *cpu,
        wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize);

    virtual ~SwitchWindow();

    //(*Declarations(SwitchWindow)
    wxCheckBox* d3;
    wxPanel* Panel1;
    wxStaticLine* StaticLine2;
    wxCheckBox* d4;
    wxStaticText* labelDec;
    wxCheckBox* d2;
    wxCheckBox* d5;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxCheckBox* d6;
    wxStaticLine* StaticLine1;
    wxStaticText* StaticText8;
    wxCheckBox* d0;
    wxStaticText* StaticText7;
    wxCheckBox* d7;
    wxCheckBox* d1;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText2;
    wxStaticText* StaticText6;
    wxStaticText* labelHex;
    wxButton* btnSelectPort;
    wxStaticText* labelPort;
    wxStaticText* StaticText9;
    wxCheckBox* generateInt;
    //*)

protected:

    bool showPortSelectDialog();
    uint8_t getValue();
    void setValue();
    void updateParentWindow();

    Cpu *cpu;
    uint8_t *in;
    int portNo;

    //(*Identifiers(SwitchWindow)
    static const long ID_CHECKBOX8;
    static const long ID_CHECKBOX7;
    static const long ID_CHECKBOX6;
    static const long ID_CHECKBOX5;
    static const long ID_CHECKBOX4;
    static const long ID_CHECKBOX3;
    static const long ID_CHECKBOX2;
    static const long ID_CHECKBOX1;
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT7;
    static const long ID_STATICTEXT8;
    static const long ID_STATICLINE1;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT11;
    static const long ID_STATICLINE2;
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT12;
    static const long ID_BUTTON1;
    static const long ID_CHECKBOX9;
    static const long ID_PANEL2;
    //*)

private:

    //(*Handlers(SwitchWindow)
    void OnCheckBoxClick(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnbtnSelectPortClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
