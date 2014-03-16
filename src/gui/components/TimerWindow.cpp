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

#include "../../wx_pch.h"
#include "TimerWindow.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(TimerWindow)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(TimerWindow)
#include <wx/font.h>
//*)

//(*IdInit(TimerWindow)
const long TimerWindow::ID_STATICTEXT1 = wxNewId();
const long TimerWindow::ID_SPINCTRL1 = wxNewId();
const long TimerWindow::ID_STATICTEXT2 = wxNewId();
const long TimerWindow::ID_SPINCTRL2 = wxNewId();
const long TimerWindow::ID_CHECKBOX2 = wxNewId();
const long TimerWindow::ID_SPINCTRL3 = wxNewId();
const long TimerWindow::ID_CHECKBOX3 = wxNewId();
const long TimerWindow::ID_SPINCTRL4 = wxNewId();
const long TimerWindow::ID_CHECKBOX1 = wxNewId();
const long TimerWindow::ID_STATICLINE1 = wxNewId();
const long TimerWindow::ID_STATICTEXT9 = wxNewId();
const long TimerWindow::ID_STATICTEXT11 = wxNewId();
const long TimerWindow::ID_STATICLINE2 = wxNewId();
const long TimerWindow::ID_BUTTON1 = wxNewId();
const long TimerWindow::ID_BUTTON2 = wxNewId();
const long TimerWindow::ID_BUTTON3 = wxNewId();
const long TimerWindow::ID_PANEL1 = wxNewId();
const long TimerWindow::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TimerWindow,wxFrame)
    //(*EventTable(TimerWindow)
    //*)
END_EVENT_TABLE()

TimerWindow::TimerWindow(MainWindow* parent, Cpu *cpu, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(TimerWindow)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Timer"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxFRAME_TOOL_WINDOW|wxFRAME_FLOAT_ON_PARENT, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Time interval (ms):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    spinInterval = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("10"), wxDefaultPosition, wxDefaultSize, 0, 0, 10000, 10, _T("ID_SPINCTRL1"));
    spinInterval->SetValue(_T("10"));
    FlexGridSizer2->Add(spinInterval, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Count up to:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    spinCount = new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("1000"), wxDefaultPosition, wxDefaultSize, 0, 0, 65535, 1000, _T("ID_SPINCTRL2"));
    spinCount->SetValue(_T("1000"));
    FlexGridSizer2->Add(spinCount, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    checkPort1 = new wxCheckBox(Panel1, ID_CHECKBOX2, _("Port A (least significant byte):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    checkPort1->SetValue(false);
    FlexGridSizer2->Add(checkPort1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    spinPort1 = new wxSpinCtrl(Panel1, ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 0, _T("ID_SPINCTRL3"));
    spinPort1->SetValue(_T("0"));
    FlexGridSizer2->Add(spinPort1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    checkPort2 = new wxCheckBox(Panel1, ID_CHECKBOX3, _("Port B (most significant byte):"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    checkPort2->SetValue(false);
    FlexGridSizer2->Add(checkPort2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    spinPort2 = new wxSpinCtrl(Panel1, ID_SPINCTRL4, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 255, 1, _T("ID_SPINCTRL4"));
    spinPort2->SetValue(_T("1"));
    FlexGridSizer2->Add(spinPort2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    checkGenerateInterrupt = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Generate interrupt on overflow"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    checkGenerateInterrupt->SetValue(false);
    FlexGridSizer1->Add(checkGenerateInterrupt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(220,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    labelDec = new wxStaticText(Panel1, ID_STATICTEXT9, _("DEC: 0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont labelDecFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    labelDec->SetFont(labelDecFont);
    BoxSizer3->Add(labelDec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    labelHex = new wxStaticText(Panel1, ID_STATICTEXT11, _("HEX: 0x00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont labelHexFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    labelHex->SetFont(labelHexFont);
    BoxSizer3->Add(labelHex, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(220,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    FlexGridSizer1->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    btnStart = new wxButton(Panel1, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(btnStart, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnStop = new wxButton(Panel1, ID_BUTTON2, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnStop->Disable();
    BoxSizer2->Add(btnStop, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnReset = new wxButton(Panel1, ID_BUTTON3, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(btnReset, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    timer.SetOwner(this, ID_TIMER1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_SPINCTRL3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&TimerWindow::OnspinPort1Change);
    Connect(ID_SPINCTRL4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&TimerWindow::OnspinPort2Change);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TimerWindow::OnbtnStartClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TimerWindow::OnbtnStopClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TimerWindow::OnbtnResetClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&TimerWindow::OntimerTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&TimerWindow::OnClose);
    //*)


    static int CID = 0;
    CID++;

    SetName(wxString::Format( wxT("Timer %d"), (int)CID ));
    SetTitle(GetName());

    this->cpu = cpu;
    this->in1 = NULL;
    this->in2 = NULL;
}

TimerWindow::~TimerWindow()
{
    //(*Destroy(TimerWindow)
    //*)
}

void TimerWindow::setValue(uint16_t value)
{
    if (this->in1 != NULL)
        *in1 = value & 0xff;

    if (this->in2 != NULL)
        *in2 = value >> 8;

    wxString str = wxString::Format(wxT("DEC: %d"), (int)value);
    labelDec->SetLabel(str);

    str = wxString::Format(wxT("HEX: 0x%04X"), (int)value);
    labelHex->SetLabel(str);
}

uint8_t *TimerWindow::attachPort(int portNo)
{
    uint8_t *res = NULL;

    if ((portNo >= 0) && (portNo < (int)Cpu::IO_PORTS_NO))
    {
        res = this->cpu->ins[portNo].attach( string(GetName().mb_str()) );

        if (res == NULL)
        {
            wxMessageBox(_("Port already in use!"), _("Error"),
                         wxICON_ERROR, this);
        }
    }

    else
    {
        wxMessageBox(_("Incorrect input data!"), _("Warning"),
                     wxICON_ERROR, this);
    }

    return res;
}

void TimerWindow::updateParentWindow()
{
    MainWindow *parent = (MainWindow*)GetParent();
    if (parent != NULL)
        parent->updateInInfo();
}


void TimerWindow::disableControls()
{
    btnStop->Enable();
    btnStart->Disable();

    spinCount->Disable();
    spinInterval->Disable();
    spinPort1->Disable();
    spinPort2->Disable();
    checkPort1->Disable();
    checkPort2->Disable();
}

void TimerWindow::enableControls()
{
    btnStart->Enable();
    btnStop->Disable();

    spinCount->Enable();
    spinInterval->Enable();
    spinPort1->Enable();
    spinPort2->Enable();
    checkPort1->Enable();
    checkPort2->Enable();
}

void TimerWindow::OnbtnStartClick(wxCommandEvent& event)
{
    this->disableControls();
    this->counter = 0;

    this->cpu->detachInput(this->in1);
    this->in1 = NULL;
    this->cpu->detachInput(this->in2);
    this->in2 = NULL;

    if (checkPort1->IsChecked())
    {
        this->in1 = this->attachPort(spinPort1->GetValue());

        if (this->in1 == NULL)
        {
            this->updateParentWindow();
            this->enableControls();
            return;
        }
    }

    if (checkPort2->IsChecked())
    {
        this->in2 = this->attachPort(spinPort2->GetValue());

        if (this->in2 == NULL)
        {
            this->enableControls();
            this->updateParentWindow();
            return;
        }
    }

    this->updateParentWindow();
    this->setValue(0);
    timer.Start(spinInterval->GetValue());
}

void TimerWindow::OnbtnStopClick(wxCommandEvent& event)
{
    timer.Stop();
    this->enableControls();
}

void TimerWindow::OntimerTrigger(wxTimerEvent& event)
{
    uint16_t count = this->counter + 1;
    bool interrupt = false;

    if ((int)count >= spinCount->GetValue())
    {
        count = 0;
        interrupt = true;
    }

    this->setValue(count);

    if ((interrupt) && (checkGenerateInterrupt->IsChecked()))
        this->cpu->generateInt();

    this->counter = count;
}

void TimerWindow::OnbtnResetClick(wxCommandEvent& event)
{
    this->counter = 0;
    this->setValue(0);
}

void TimerWindow::OnClose(wxCloseEvent& event)
{
    timer.Stop();
    this->cpu->detachInput(this->in1);
    this->cpu->detachInput(this->in2);
    this->updateParentWindow();

    event.Skip();
}

void TimerWindow::OnspinPort1Change(wxSpinEvent& event)
{
    checkPort1->SetValue(true);
}

void TimerWindow::OnspinPort2Change(wxSpinEvent& event)
{
    checkPort2->SetValue(true);
}
