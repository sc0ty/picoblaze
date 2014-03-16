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

#include <wx/numdlg.h>

#include "../../wx_pch.h"
#include "KeyboardWindow.h"

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(KeyboardWindow)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(KeyboardWindow)
#include <wx/font.h>
//*)

//(*IdInit(KeyboardWindow)
const long KeyboardWindow::ID_BUTTON1 = wxNewId();
const long KeyboardWindow::ID_BUTTON9 = wxNewId();
const long KeyboardWindow::ID_BUTTON2 = wxNewId();
const long KeyboardWindow::ID_BUTTON14 = wxNewId();
const long KeyboardWindow::ID_BUTTON15 = wxNewId();
const long KeyboardWindow::ID_BUTTON5 = wxNewId();
const long KeyboardWindow::ID_BUTTON6 = wxNewId();
const long KeyboardWindow::ID_BUTTON7 = wxNewId();
const long KeyboardWindow::ID_BUTTON8 = wxNewId();
const long KeyboardWindow::ID_BUTTON10 = wxNewId();
const long KeyboardWindow::ID_BUTTON11 = wxNewId();
const long KeyboardWindow::ID_BUTTON12 = wxNewId();
const long KeyboardWindow::ID_BUTTON13 = wxNewId();
const long KeyboardWindow::ID_BUTTON3 = wxNewId();
const long KeyboardWindow::ID_BUTTON4 = wxNewId();
const long KeyboardWindow::ID_BUTTON16 = wxNewId();
const long KeyboardWindow::ID_BUTTON19 = wxNewId();
const long KeyboardWindow::ID_BUTTON18 = wxNewId();
const long KeyboardWindow::ID_STATICLINE2 = wxNewId();
const long KeyboardWindow::ID_STATICTEXT10 = wxNewId();
const long KeyboardWindow::ID_STATICTEXT12 = wxNewId();
const long KeyboardWindow::ID_BUTTON17 = wxNewId();
const long KeyboardWindow::ID_STATICLINE1 = wxNewId();
const long KeyboardWindow::ID_CHECKBOX1 = wxNewId();
const long KeyboardWindow::ID_CHECKBOX9 = wxNewId();
const long KeyboardWindow::ID_PANEL1 = wxNewId();
const long KeyboardWindow::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KeyboardWindow,wxFrame)
    //(*EventTable(KeyboardWindow)
    //*)
END_EVENT_TABLE()

KeyboardWindow::KeyboardWindow(MainWindow* parent, Cpu *cpu, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(KeyboardWindow)
    wxGridSizer* GridSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Keyboard"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxFRAME_TOOL_WINDOW|wxFRAME_FLOAT_ON_PARENT, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    GridSizer1 = new wxGridSizer(0, 6, 0, 0);
    btn7 = new wxToggleButton(Panel1, ID_BUTTON1, _("7"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    GridSizer1->Add(btn7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn8 = new wxToggleButton(Panel1, ID_BUTTON9, _("8"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    GridSizer1->Add(btn8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn9 = new wxToggleButton(Panel1, ID_BUTTON2, _("9"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GridSizer1->Add(btn9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnA = new wxToggleButton(Panel1, ID_BUTTON14, _("A"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON14"));
    GridSizer1->Add(btnA, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnB = new wxToggleButton(Panel1, ID_BUTTON15, _("B"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON15"));
    GridSizer1->Add(btnB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn4 = new wxToggleButton(Panel1, ID_BUTTON5, _("4"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    GridSizer1->Add(btn4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn5 = new wxToggleButton(Panel1, ID_BUTTON6, _("5"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    GridSizer1->Add(btn5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn6 = new wxToggleButton(Panel1, ID_BUTTON7, _("6"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    GridSizer1->Add(btn6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnC = new wxToggleButton(Panel1, ID_BUTTON8, _("C"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    GridSizer1->Add(btnC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnD = new wxToggleButton(Panel1, ID_BUTTON10, _("D"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    GridSizer1->Add(btnD, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn1 = new wxToggleButton(Panel1, ID_BUTTON11, _("1"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    GridSizer1->Add(btn1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn2 = new wxToggleButton(Panel1, ID_BUTTON12, _("2"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    GridSizer1->Add(btn2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn3 = new wxToggleButton(Panel1, ID_BUTTON13, _("3"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    GridSizer1->Add(btn3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnE = new wxToggleButton(Panel1, ID_BUTTON3, _("E"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    GridSizer1->Add(btnE, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnF = new wxToggleButton(Panel1, ID_BUTTON4, _("F"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    GridSizer1->Add(btnF, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btn0 = new wxToggleButton(Panel1, ID_BUTTON16, _("0"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON16"));
    GridSizer1->Add(btn0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnEnter = new wxToggleButton(Panel1, ID_BUTTON19, _("Ent"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON19"));
    wxFont btnEnterFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    btnEnter->SetFont(btnEnterFont);
    GridSizer1->Add(btnEnter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnEsc = new wxToggleButton(Panel1, ID_BUTTON18, _("Esc"), wxDefaultPosition, wxSize(50,50), 0, wxDefaultValidator, _T("ID_BUTTON18"));
    wxFont btnEscFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    btnEsc->SetFont(btnEscFont);
    GridSizer1->Add(btnEsc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    FlexGridSizer1->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Input no:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer3->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    labelPort = new wxStaticText(Panel1, ID_STATICTEXT12, _("<none>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer3->Add(labelPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSelectPort = new wxButton(Panel1, ID_BUTTON17, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON17"));
    BoxSizer3->Add(btnSelectPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    checkGenerateInt = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Generate interrupt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    checkGenerateInt->SetValue(false);
    BoxSizer2->Add(checkGenerateInt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    checkTempButtons = new wxCheckBox(Panel1, ID_CHECKBOX9, _("Monostable buttons"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    checkTempButtons->SetValue(false);
    BoxSizer2->Add(checkTempButtons, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 10);
    FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    timerRelease.SetOwner(this, ID_TIMER1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn7Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn8Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn9Click);
    Connect(ID_BUTTON14,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnAClick);
    Connect(ID_BUTTON15,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnBClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn4Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn5Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn6Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnCClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnDClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn1Click);
    Connect(ID_BUTTON12,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn2Click);
    Connect(ID_BUTTON13,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn3Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnEClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnFClick);
    Connect(ID_BUTTON16,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::Onbtn0Click);
    Connect(ID_BUTTON19,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnEnterClick);
    Connect(ID_BUTTON18,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnEscClick);
    Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KeyboardWindow::OnbtnSelectPortClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&KeyboardWindow::OntimerReleaseTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&KeyboardWindow::OnClose);
    //*)

    static int CID = 0;
    CID++;

    SetName(wxString::Format( wxT("Keyboard %d"), (int)CID ));
    SetTitle(GetName());

    this->cpu = cpu;
    this->in = NULL;
    this->portNo = -1;

    if (!this->showPortSelectDialog())
        Close();
}

KeyboardWindow::~KeyboardWindow()
{
    //(*Destroy(KeyboardWindow)
    //*)
}

bool KeyboardWindow::showPortSelectDialog()
{
    long res;

    res = wxGetNumberFromUser(_("Select port number"),
                              _("Port:"), _("Keyboard"), this->portNo,
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
                this->setValue(0x80, false);
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

void KeyboardWindow::setValue(uint8_t value, bool interrupt)
{
    if (this->in != NULL)
        *in = value;

    if ((interrupt) && (checkGenerateInt->IsChecked()))
        this->cpu->generateInt();
}

void KeyboardWindow::updateParentWindow()
{
    MainWindow *parent = (MainWindow*)GetParent();
    if (parent != NULL)
        parent->updateInInfo();
}

void KeyboardWindow::pushKey(uint8_t key, bool down)
{
    if (down)
    {
        this->setValue(key);

        if (checkTempButtons->IsChecked())
            timerRelease.Start(100, true);
    }

    else
        this->setValue(0x80);

    if (key != 0) btn0->SetValue(false);
    if (key != 1) btn1->SetValue(false);
    if (key != 2) btn2->SetValue(false);
    if (key != 3) btn3->SetValue(false);
    if (key != 4) btn4->SetValue(false);
    if (key != 5) btn5->SetValue(false);
    if (key != 6) btn6->SetValue(false);
    if (key != 7) btn7->SetValue(false);
    if (key != 8) btn8->SetValue(false);
    if (key != 9) btn9->SetValue(false);
    if (key != 0xa) btnA->SetValue(false);
    if (key != 0xb) btnB->SetValue(false);
    if (key != 0xc) btnC->SetValue(false);
    if (key != 0xd) btnD->SetValue(false);
    if (key != 0xe) btnE->SetValue(false);
    if (key != 0xf) btnF->SetValue(false);
    if (key != 0x10) btnEnter->SetValue(false);
    if (key != 0x20) btnEsc->SetValue(false);
}

void KeyboardWindow::OnbtnSelectPortClick(wxCommandEvent& event)
{
    this->showPortSelectDialog();
}

void KeyboardWindow::Onbtn0Click(wxCommandEvent& event)
{
    this->pushKey(0, event.IsChecked());
}

void KeyboardWindow::Onbtn1Click(wxCommandEvent& event)
{
    this->pushKey(1, event.IsChecked());
}

void KeyboardWindow::Onbtn2Click(wxCommandEvent& event)
{
    this->pushKey(2, event.IsChecked());
}

void KeyboardWindow::Onbtn3Click(wxCommandEvent& event)
{
    this->pushKey(3, event.IsChecked());
}

void KeyboardWindow::Onbtn4Click(wxCommandEvent& event)
{
    this->pushKey(4, event.IsChecked());
}

void KeyboardWindow::Onbtn5Click(wxCommandEvent& event)
{
    this->pushKey(5, event.IsChecked());
}

void KeyboardWindow::Onbtn6Click(wxCommandEvent& event)
{
    this->pushKey(6, event.IsChecked());
}

void KeyboardWindow::Onbtn7Click(wxCommandEvent& event)
{
    this->pushKey(7, event.IsChecked());
}

void KeyboardWindow::Onbtn8Click(wxCommandEvent& event)
{
    this->pushKey(8, event.IsChecked());
}

void KeyboardWindow::Onbtn9Click(wxCommandEvent& event)
{
    this->pushKey(9, event.IsChecked());
}

void KeyboardWindow::OnbtnAClick(wxCommandEvent& event)
{
    this->pushKey(0xa, event.IsChecked());
}

void KeyboardWindow::OnbtnBClick(wxCommandEvent& event)
{
    this->pushKey(0xb, event.IsChecked());
}

void KeyboardWindow::OnbtnCClick(wxCommandEvent& event)
{
    this->pushKey(0xc, event.IsChecked());
}

void KeyboardWindow::OnbtnDClick(wxCommandEvent& event)
{
    this->pushKey(0xd, event.IsChecked());
}

void KeyboardWindow::OnbtnEClick(wxCommandEvent& event)
{
    this->pushKey(0xe, event.IsChecked());
}

void KeyboardWindow::OnbtnFClick(wxCommandEvent& event)
{
    this->pushKey(0xf, event.IsChecked());
}

void KeyboardWindow::OnbtnEnterClick(wxCommandEvent& event)
{
    this->pushKey(0x10, event.IsChecked());
}

void KeyboardWindow::OnbtnEscClick(wxCommandEvent& event)
{
    this->pushKey(0x20, event.IsChecked());
}

void KeyboardWindow::OntimerReleaseTrigger(wxTimerEvent& event)
{
    this->pushKey(0x80, false);
}

void KeyboardWindow::OnClose(wxCloseEvent& event)
{
    this->cpu->detachInput(this->in);
    this->updateParentWindow();
    event.Skip();
}
