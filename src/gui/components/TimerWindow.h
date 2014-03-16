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

	Device window - timer
*/

#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#ifndef WX_PRECOMP
//(*HeadersPCH(TimerWindow)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)
#endif
//(*Headers(TimerWindow)
#include <wx/spinctrl.h>
#include <wx/statline.h>
//*)

#include "../../cpu/cpu.h"
#include "../MainWindow.h"

class TimerWindow: public wxFrame
{
public:

    TimerWindow(MainWindow* parent,
                Cpu *cpu,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize);

    virtual ~TimerWindow();

    //(*Declarations(TimerWindow)
    wxSpinCtrl* spinCount;
    wxTimer timer;
    wxSpinCtrl* spinInterval;
    wxPanel* Panel1;
    wxStaticLine* StaticLine2;
    wxButton* btnReset;
    wxStaticText* labelDec;
    wxStaticText* StaticText1;
    wxSpinCtrl* spinPort1;
    wxSpinCtrl* spinPort2;
    wxButton* btnStop;
    wxCheckBox* checkPort2;
    wxStaticLine* StaticLine1;
    wxCheckBox* checkGenerateInterrupt;
    wxCheckBox* checkPort1;
    wxStaticText* StaticText2;
    wxStaticText* labelHex;
    wxButton* btnStart;
    //*)

protected:

    void setValue(uint16_t value);
    uint8_t *attachPort(int portNo);

    void updateParentWindow();

    void disableControls();
    void enableControls();

    Cpu *cpu;
    uint8_t *in1, *in2;
    uint16_t counter;

    //(*Identifiers(TimerWindow)
    static const long ID_STATICTEXT1;
    static const long ID_SPINCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_SPINCTRL2;
    static const long ID_CHECKBOX2;
    static const long ID_SPINCTRL3;
    static const long ID_CHECKBOX3;
    static const long ID_SPINCTRL4;
    static const long ID_CHECKBOX1;
    static const long ID_STATICLINE1;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT11;
    static const long ID_STATICLINE2;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_PANEL1;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(TimerWindow)
    void OnbtnStartClick(wxCommandEvent& event);
    void OnbtnStopClick(wxCommandEvent& event);
    void OntimerTrigger(wxTimerEvent& event);
    void OnbtnResetClick(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnspinPort1Change(wxSpinEvent& event);
    void OnspinPort2Change(wxSpinEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
