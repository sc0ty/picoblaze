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

	Device window - terminal
*/

#ifndef TERMWINDOW_H
#define TERMWINDOW_H

#ifndef WX_PRECOMP
//(*HeadersPCH(TermWindow)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)
#endif
//(*Headers(TermWindow)
#include <wx/statline.h>
//*)

#include "../../cpu/cpu.h"
#include "../MainWindow.h"

class TermWindow: public wxFrame, public Output
{
public:

    TermWindow(
        MainWindow* parent,
        Cpu *cpu,
        wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize);

    virtual ~TermWindow();

    void set(uint8_t value);

    string getName();

    //(*Declarations(TermWindow)
    wxPanel* Panel1;
    wxStaticLine* StaticLine2;
    wxButton* btnClear;
    wxTextCtrl* textTerm;
    wxButton* btnOk;
    wxStaticLine* StaticLine1;
    wxCheckBox* checkGenerateInt;
    wxTimer timerPool;
    wxTextCtrl* textInput;
    wxButton* btnSelectPort;
    wxStaticText* labelPort;
    wxCheckBox* checkEcho;
    wxStaticText* StaticText9;
    //*)

protected:

    Cpu *cpu;
    uint8_t *in;
    int portNo;
    wxString str;
    wxMutex mutex;

    bool showPortSelectDialog();
    void sendChar(wxChar ch);
    void updateParentWindow();

    //(*Identifiers(TermWindow)
    static const long ID_TEXTCTRL1;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON1;
    static const long ID_BUTTON3;
    static const long ID_STATICLINE2;
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT12;
    static const long ID_BUTTON2;
    static const long ID_STATICLINE1;
    static const long ID_CHECKBOX9;
    static const long ID_CHECKBOX1;
    static const long ID_PANEL1;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(TermWindow)
    void OnbtnSelectPortClick(wxCommandEvent& event);
    void OntextInputTextEnter(wxCommandEvent& event);
    void OntimerPoolTrigger(wxTimerEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnbtnClearClick(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
