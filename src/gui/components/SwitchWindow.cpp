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

#include <wx/numdlg.h>

#include "../../wx_pch.h"
#include "SwitchWindow.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(SwitchWindow)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(SwitchWindow)
#include <wx/font.h>
//*)

//(*IdInit(SwitchWindow)
const long SwitchWindow::ID_CHECKBOX8 = wxNewId();
const long SwitchWindow::ID_CHECKBOX7 = wxNewId();
const long SwitchWindow::ID_CHECKBOX6 = wxNewId();
const long SwitchWindow::ID_CHECKBOX5 = wxNewId();
const long SwitchWindow::ID_CHECKBOX4 = wxNewId();
const long SwitchWindow::ID_CHECKBOX3 = wxNewId();
const long SwitchWindow::ID_CHECKBOX2 = wxNewId();
const long SwitchWindow::ID_CHECKBOX1 = wxNewId();
const long SwitchWindow::ID_STATICTEXT1 = wxNewId();
const long SwitchWindow::ID_STATICTEXT2 = wxNewId();
const long SwitchWindow::ID_STATICTEXT3 = wxNewId();
const long SwitchWindow::ID_STATICTEXT4 = wxNewId();
const long SwitchWindow::ID_STATICTEXT5 = wxNewId();
const long SwitchWindow::ID_STATICTEXT6 = wxNewId();
const long SwitchWindow::ID_STATICTEXT7 = wxNewId();
const long SwitchWindow::ID_STATICTEXT8 = wxNewId();
const long SwitchWindow::ID_STATICLINE1 = wxNewId();
const long SwitchWindow::ID_STATICTEXT9 = wxNewId();
const long SwitchWindow::ID_STATICTEXT11 = wxNewId();
const long SwitchWindow::ID_STATICLINE2 = wxNewId();
const long SwitchWindow::ID_STATICTEXT10 = wxNewId();
const long SwitchWindow::ID_STATICTEXT12 = wxNewId();
const long SwitchWindow::ID_BUTTON1 = wxNewId();
const long SwitchWindow::ID_CHECKBOX9 = wxNewId();
const long SwitchWindow::ID_PANEL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SwitchWindow,wxFrame)
    //(*EventTable(SwitchWindow)
    //*)
END_EVENT_TABLE()

SwitchWindow::SwitchWindow(MainWindow* parent, Cpu *cpu, wxWindowID id,
                           const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(SwitchWindow)
    wxGridSizer* GridSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;

    Create(parent, id, _("Switches"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxFRAME_TOOL_WINDOW|wxFRAME_FLOAT_ON_PARENT, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    GridSizer1 = new wxGridSizer(0, 8, 0, 0);
    d7 = new wxCheckBox(Panel1, ID_CHECKBOX8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    d7->SetValue(false);
    GridSizer1->Add(d7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d6 = new wxCheckBox(Panel1, ID_CHECKBOX7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    d6->SetValue(false);
    GridSizer1->Add(d6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d5 = new wxCheckBox(Panel1, ID_CHECKBOX6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    d5->SetValue(false);
    GridSizer1->Add(d5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d4 = new wxCheckBox(Panel1, ID_CHECKBOX5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    d4->SetValue(false);
    GridSizer1->Add(d4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d3 = new wxCheckBox(Panel1, ID_CHECKBOX4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    d3->SetValue(false);
    GridSizer1->Add(d3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d2 = new wxCheckBox(Panel1, ID_CHECKBOX3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    d2->SetValue(false);
    GridSizer1->Add(d2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d1 = new wxCheckBox(Panel1, ID_CHECKBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    d1->SetValue(false);
    GridSizer1->Add(d1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    d0 = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    d0->SetValue(false);
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
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Input no:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer3->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    labelPort = new wxStaticText(Panel1, ID_STATICTEXT12, _("<none>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer3->Add(labelPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSelectPort = new wxButton(Panel1, ID_BUTTON1, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer3->Add(btnSelectPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    generateInt = new wxCheckBox(Panel1, ID_CHECKBOX9, _("Generate interrupt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    generateInt->SetValue(false);
    FlexGridSizer1->Add(generateInt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_CHECKBOX8,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX7,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX6,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX5,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX4,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnCheckBoxClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SwitchWindow::OnbtnSelectPortClick);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&SwitchWindow::OnClose);
    //*)

    static int CID = 0;
    CID++;

    SetName(wxString::Format( wxT("Switches %d"), (int)CID ));
    SetTitle(GetName());

    this->cpu = cpu;
    this->in = NULL;
    this->portNo = -1;

    if (!this->showPortSelectDialog())
        Close();
}

SwitchWindow::~SwitchWindow()
{
    //(*Destroy(SwitchWindow)
    //*)
}

bool SwitchWindow::showPortSelectDialog()
{
    long res;

    res = wxGetNumberFromUser(_("Select port number"),
                              _("Port:"), _("Switches"), this->portNo,
                              0, Cpu::IO_PORTS_NO-1, this);

    if ((res >= 0) && (res < (long)Cpu::IO_PORTS_NO))
    {
        if (res != this->portNo)
        {
            this->cpu->detachInput(this->in);
            this->in = this->cpu->ins[res].attach( string(GetName().mb_str()) );

            if (this->in != NULL)
            {
                wxString str = wxString::Format(wxT("%d   (0x%02X)"), res, res);
                labelPort->SetLabel(str);
                this->setValue();
            }
            else
            {
                wxMessageBox(_("Port already in use!"), _("Error"),
                             wxICON_ERROR, this);
                labelPort->SetLabel(_("<none>"));
            }
        }

        this->updateParentWindow();
        return true;
    }

    return false;
}

uint8_t SwitchWindow::getValue()
{
    uint8_t val = d0->IsChecked();
    val |= d1->IsChecked() << 1;
    val |= d2->IsChecked() << 2;
    val |= d3->IsChecked() << 3;
    val |= d4->IsChecked() << 4;
    val |= d5->IsChecked() << 5;
    val |= d6->IsChecked() << 6;
    val |= d7->IsChecked() << 7;

    return val;
}

void SwitchWindow::setValue()
{
    if (this->in == NULL)
    {
        labelDec->SetLabel(_("port not set"));
        labelHex->Hide();
    }
    else
    {
        uint8_t value = this->getValue();
        wxString str = wxString::Format(wxT("DEC: %d"), (int)value);
        labelDec->SetLabel(str);

        str = wxString::Format(wxT("HEX: 0x%02X"), (int)value);
        labelHex->SetLabel(str);
        labelHex->Show();

        *in = value;
    }
}

void SwitchWindow::updateParentWindow()
{
    MainWindow *parent = (MainWindow*)GetParent();
    if (parent != NULL)
        parent->updateInInfo();
}

void SwitchWindow::OnCheckBoxClick(wxCommandEvent& event)
{
    this->setValue();
    if (this->generateInt->IsChecked())
        this->cpu->generateInt();
}

void SwitchWindow::OnClose(wxCloseEvent& event)
{
    this->cpu->detachInput(this->in);
    this->updateParentWindow();
    event.Skip();
}

void SwitchWindow::OnbtnSelectPortClick(wxCommandEvent& event)
{
    this->showPortSelectDialog();
}
