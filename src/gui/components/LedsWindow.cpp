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

#include <wx/numdlg.h>

#include "../../wx_pch.h"
#include "LedsWindow.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(LedsWindow)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(LedsWindow)
#include <wx/font.h>
//*)

//(*IdInit(LedsWindow)
const long LedsWindow::ID_CHECKBOX1 = wxNewId();
const long LedsWindow::ID_CHECKBOX2 = wxNewId();
const long LedsWindow::ID_CHECKBOX3 = wxNewId();
const long LedsWindow::ID_CHECKBOX4 = wxNewId();
const long LedsWindow::ID_CHECKBOX5 = wxNewId();
const long LedsWindow::ID_CHECKBOX6 = wxNewId();
const long LedsWindow::ID_CHECKBOX7 = wxNewId();
const long LedsWindow::ID_CHECKBOX8 = wxNewId();
const long LedsWindow::ID_STATICTEXT1 = wxNewId();
const long LedsWindow::ID_STATICTEXT2 = wxNewId();
const long LedsWindow::ID_STATICTEXT3 = wxNewId();
const long LedsWindow::ID_STATICTEXT4 = wxNewId();
const long LedsWindow::ID_STATICTEXT5 = wxNewId();
const long LedsWindow::ID_STATICTEXT6 = wxNewId();
const long LedsWindow::ID_STATICTEXT7 = wxNewId();
const long LedsWindow::ID_STATICTEXT8 = wxNewId();
const long LedsWindow::ID_STATICLINE1 = wxNewId();
const long LedsWindow::ID_STATICTEXT9 = wxNewId();
const long LedsWindow::ID_STATICTEXT11 = wxNewId();
const long LedsWindow::ID_STATICLINE2 = wxNewId();
const long LedsWindow::ID_STATICTEXT10 = wxNewId();
const long LedsWindow::ID_STATICTEXT12 = wxNewId();
const long LedsWindow::ID_BUTTON1 = wxNewId();
const long LedsWindow::ID_PANEL1 = wxNewId();
const long LedsWindow::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LedsWindow,wxFrame)
    //(*EventTable(LedsWindow)
    //*)
END_EVENT_TABLE()

LedsWindow::LedsWindow(MainWindow* parent, Cpu *cpu, wxWindowID id,
                       const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(LedsWindow)
    wxGridSizer* GridSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("LEDs"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxFRAME_TOOL_WINDOW|wxFRAME_FLOAT_ON_PARENT, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    GridSizer1 = new wxGridSizer(0, 8, 0, 0);
    d7 = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    d7->SetValue(false);
    d7->Disable();
    GridSizer1->Add(d7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d6 = new wxCheckBox(Panel1, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    d6->SetValue(false);
    d6->Disable();
    GridSizer1->Add(d6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d5 = new wxCheckBox(Panel1, ID_CHECKBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    d5->SetValue(false);
    d5->Disable();
    GridSizer1->Add(d5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d4 = new wxCheckBox(Panel1, ID_CHECKBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    d4->SetValue(false);
    d4->Disable();
    GridSizer1->Add(d4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d3 = new wxCheckBox(Panel1, ID_CHECKBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    d3->SetValue(false);
    d3->Disable();
    GridSizer1->Add(d3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d2 = new wxCheckBox(Panel1, ID_CHECKBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    d2->SetValue(false);
    d2->Disable();
    GridSizer1->Add(d2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d1 = new wxCheckBox(Panel1, ID_CHECKBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    d1->SetValue(false);
    d1->Disable();
    GridSizer1->Add(d1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d0 = new wxCheckBox(Panel1, ID_CHECKBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    d0->SetValue(false);
    d0->Disable();
    GridSizer1->Add(d0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("7"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("6"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("5"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    GridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("4"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    GridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("3"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("1"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(GridSizer1, 0, wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(182,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    labelDec = new wxStaticText(Panel1, ID_STATICTEXT9, _("DEC: 0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont labelDecFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    labelDec->SetFont(labelDecFont);
    BoxSizer2->Add(labelDec, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    labelHex = new wxStaticText(Panel1, ID_STATICTEXT11, _("HEX: 0x00"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont labelHexFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    labelHex->SetFont(labelHexFont);
    BoxSizer2->Add(labelHex, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(182,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    FlexGridSizer1->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Output no:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer3->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    labelPort = new wxStaticText(Panel1, ID_STATICTEXT12, _("<none>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer3->Add(labelPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSelectPort = new wxButton(Panel1, ID_BUTTON1, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(btnSelectPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    timerPool.SetOwner(this, ID_TIMER1);
    timerPool.Start(50, false);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&LedsWindow::OnbtnSelectPortClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&LedsWindow::OntimerPoolTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&LedsWindow::OnClose);
    //*)

    static int CID = 0;
    CID++;

    SetName(wxString::Format( wxT("LEDs %d"), (int)CID ));
    SetTitle(GetName());

    this->value = this->lastValue = 0;
    this->cpu = cpu;
    this->portNo = -1;

    if (!this->showPortSelectDialog())
        Close();
}

LedsWindow::~LedsWindow()
{
    //(*Destroy(LedsWindow)
    //*)
}

void LedsWindow::set(uint8_t value)
{
    this->value = value;
}

string LedsWindow::getName()
{
    return string( GetName().mb_str() );
}

void LedsWindow::setLabels(int value)
{
    wxString str = wxString::Format(wxT("DEC: %d"), (int)value);
    labelDec->SetLabel(str);

    str = wxString::Format(wxT("HEX: 0x%02X"), (int)value);
    labelHex->SetLabel(str);
}

bool LedsWindow::showPortSelectDialog()
{
    long res;

    res = wxGetNumberFromUser(_("Select port number"),
                              _("Port:"), _("LEDs"), (long)this->portNo,
                              0, Cpu::IO_PORTS_NO-1, this);

    if ((res >= 0) && (res < (long)Cpu::IO_PORTS_NO))
    {
        if (res != this->portNo)
        {
            this->portNo = res;

            this->cpu->detachOutput(this);
            this->cpu->outs[res].attach(this);

            wxString str = wxString::Format(wxT("%d   (0x%02X)"), res, res);
            labelPort->SetLabel(str);
        }

        this->updateParentWindow();
        return true;
    }

    return false;
}

void LedsWindow::updateParentWindow()
{
    MainWindow *parent = (MainWindow*)GetParent();
    if (parent != NULL)
        parent->updateOutInfo();
}

void LedsWindow::OnClose(wxCloseEvent& event)
{
    this->cpu->detachOutput(this);
    this->updateParentWindow();
    event.Skip();
}

void LedsWindow::OntimerPoolTrigger(wxTimerEvent& event)
{
    if (this->value != this->lastValue)
    {
        d0->SetValue(value & 1);
        d1->SetValue(value & 2);
        d2->SetValue(value & 4);
        d3->SetValue(value & 8);
        d4->SetValue(value & 0x10);
        d5->SetValue(value & 0x20);
        d6->SetValue(value & 0x40);
        d7->SetValue(value & 0x80);

        this->setLabels(this->value);
        this->lastValue = this->value;
    }
}

void LedsWindow::OnbtnSelectPortClick(wxCommandEvent& event)
{
    this->showPortSelectDialog();
}
