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

	Device window - LEDs
*/

#ifndef LEDSWINDOW_H
#define LEDSWINDOW_H

#ifndef WX_PRECOMP
//(*HeadersPCH(LedsWindow)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)
#endif
//(*Headers(LedsWindow)
#include <wx/statline.h>
//*)

#include "../../cpu/cpu.h"
#include "../MainWindow.h"

class LedsWindow: public wxFrame, public Output
{
public:

    LedsWindow(
        MainWindow* parent,
        Cpu *cpu,
        wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize);

    virtual ~LedsWindow();

    void set(uint8_t value);
    string getName();

    //(*Declarations(LedsWindow)
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
    wxTimer timerPool;
    wxStaticText* StaticText6;
    wxStaticText* labelHex;
    wxButton* btnSelectPort;
    wxStaticText* labelPort;
    wxStaticText* StaticText9;
    //*)

protected:

    void setLabels(int value);
    bool showPortSelectDialog();
    void updateParentWindow();

    Cpu *cpu;
    uint8_t value, lastValue;
    int portNo;

    //(*Identifiers(LedsWindow)
    static const long ID_CHECKBOX1;
    static const long ID_CHECKBOX2;
    static const long ID_CHECKBOX3;
    static const long ID_CHECKBOX4;
    static const long ID_CHECKBOX5;
    static const long ID_CHECKBOX6;
    static const long ID_CHECKBOX7;
    static const long ID_CHECKBOX8;
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
    static const long ID_PANEL1;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(LedsWindow)
    void OnClose(wxCloseEvent& event);
    void OntimerPoolTrigger(wxTimerEvent& event);
    void OnbtnSelectPortClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
