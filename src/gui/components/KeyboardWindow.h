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

	Device window - keyboard
*/

#ifndef KEYBOARDWINDOW_H
#define KEYBOARDWINDOW_H

#ifndef WX_PRECOMP
//(*HeadersPCH(KeyboardWindow)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)
#endif
//(*Headers(KeyboardWindow)
#include <wx/statline.h>
#include <wx/tglbtn.h>
//*)

#include "../../cpu/cpu.h"
#include "../MainWindow.h"

class KeyboardWindow: public wxFrame
{
public:

    KeyboardWindow(
        MainWindow* parent,
        Cpu *cpu,
        wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize);

    virtual ~KeyboardWindow();

    //(*Declarations(KeyboardWindow)
    wxToggleButton* btnEsc;
    wxPanel* Panel1;
    wxStaticLine* StaticLine2;
    wxToggleButton* btnD;
    wxToggleButton* btnE;
    wxToggleButton* btn2;
    wxToggleButton* btnB;
    wxToggleButton* btnA;
    wxToggleButton* btnC;
    wxToggleButton* btn0;
    wxToggleButton* btn5;
    wxToggleButton* btnF;
    wxStaticLine* StaticLine1;
    wxCheckBox* checkTempButtons;
    wxToggleButton* btnEnter;
    wxToggleButton* btn3;
    wxToggleButton* btn6;
    wxCheckBox* checkGenerateInt;
    wxToggleButton* btn1;
    wxToggleButton* btn8;
    wxToggleButton* btn7;
    wxButton* btnSelectPort;
    wxStaticText* labelPort;
    wxTimer timerRelease;
    wxToggleButton* btn9;
    wxStaticText* StaticText9;
    wxToggleButton* btn4;
    //*)

protected:

    bool showPortSelectDialog();
    void setValue(uint8_t value, bool interrupt=true);
    void updateParentWindow();

    void pushKey(uint8_t key, bool);

    Cpu *cpu;
    uint8_t *in;
    int portNo;

    //(*Identifiers(KeyboardWindow)
    static const long ID_BUTTON1;
    static const long ID_BUTTON9;
    static const long ID_BUTTON2;
    static const long ID_BUTTON14;
    static const long ID_BUTTON15;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_BUTTON7;
    static const long ID_BUTTON8;
    static const long ID_BUTTON10;
    static const long ID_BUTTON11;
    static const long ID_BUTTON12;
    static const long ID_BUTTON13;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    static const long ID_BUTTON16;
    static const long ID_BUTTON19;
    static const long ID_BUTTON18;
    static const long ID_STATICLINE2;
    static const long ID_STATICTEXT10;
    static const long ID_STATICTEXT12;
    static const long ID_BUTTON17;
    static const long ID_STATICLINE1;
    static const long ID_CHECKBOX1;
    static const long ID_CHECKBOX9;
    static const long ID_PANEL1;
    static const long ID_TIMER1;
    //*)

private:

    //(*Handlers(KeyboardWindow)
    void OnbtnSelectPortClick(wxCommandEvent& event);
    void OnbtnClick(wxCommandEvent& event);
    void Onbtn0Click(wxCommandEvent& event);
    void Onbtn1Click(wxCommandEvent& event);
    void Onbtn2Click(wxCommandEvent& event);
    void Onbtn3Click(wxCommandEvent& event);
    void Onbtn4Click(wxCommandEvent& event);
    void Onbtn5Click(wxCommandEvent& event);
    void Onbtn6Click(wxCommandEvent& event);
    void Onbtn7Click(wxCommandEvent& event);
    void Onbtn8Click(wxCommandEvent& event);
    void Onbtn9Click(wxCommandEvent& event);
    void OnbtnAClick(wxCommandEvent& event);
    void OnbtnBClick(wxCommandEvent& event);
    void OnbtnCClick(wxCommandEvent& event);
    void OnbtnDClick(wxCommandEvent& event);
    void OnbtnEClick(wxCommandEvent& event);
    void OnbtnFClick(wxCommandEvent& event);
    void OnbtnEnterClick(wxCommandEvent& event);
    void OnbtnEscClick(wxCommandEvent& event);
    void OntimerReleaseTrigger(wxTimerEvent& event);
    void OntimerReleaseTrigger1(wxTimerEvent& event);
    void OnClose(wxCloseEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
