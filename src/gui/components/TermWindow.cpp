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

#include "../../wx_pch.h"
#include "TermWindow.h"

#include <wx/numdlg.h>

#ifndef WX_PRECOMP
//(*InternalHeadersPCH(TermWindow)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#endif
//(*InternalHeaders(TermWindow)
#include <wx/font.h>
//*)

//(*IdInit(TermWindow)
const long TermWindow::ID_TEXTCTRL1 = wxNewId();
const long TermWindow::ID_TEXTCTRL2 = wxNewId();
const long TermWindow::ID_BUTTON1 = wxNewId();
const long TermWindow::ID_BUTTON3 = wxNewId();
const long TermWindow::ID_STATICLINE2 = wxNewId();
const long TermWindow::ID_STATICTEXT10 = wxNewId();
const long TermWindow::ID_STATICTEXT12 = wxNewId();
const long TermWindow::ID_BUTTON2 = wxNewId();
const long TermWindow::ID_STATICLINE1 = wxNewId();
const long TermWindow::ID_CHECKBOX9 = wxNewId();
const long TermWindow::ID_CHECKBOX1 = wxNewId();
const long TermWindow::ID_PANEL1 = wxNewId();
const long TermWindow::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TermWindow,wxFrame)
    //(*EventTable(TermWindow)
    //*)
END_EVENT_TABLE()

TermWindow::TermWindow(MainWindow* parent, Cpu *cpu, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(TermWindow)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;

    Create(parent, wxID_ANY, _("Terminal"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxFRAME_TOOL_WINDOW|wxFRAME_FLOAT_ON_PARENT, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    textTerm = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(367,274), wxTE_AUTO_SCROLL|wxTE_MULTILINE|wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont textTermFont(10,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    textTerm->SetFont(textTermFont);
    FlexGridSizer1->Add(textTerm, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    textInput = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(230,27), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    wxFont textInputFont(10,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Monospace"),wxFONTENCODING_DEFAULT);
    textInput->SetFont(textInputFont);
    FlexGridSizer2->Add(textInput, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOk = new wxButton(Panel1, ID_BUTTON1, _("OK"), wxDefaultPosition, wxSize(56,29), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(btnOk, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnClear = new wxButton(Panel1, ID_BUTTON3, _("Clear"), wxDefaultPosition, wxSize(56,29), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer2->Add(btnClear, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    FlexGridSizer1->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Port no:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    BoxSizer3->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    labelPort = new wxStaticText(Panel1, ID_STATICTEXT12, _("<none>"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    BoxSizer3->Add(labelPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSelectPort = new wxButton(Panel1, ID_BUTTON2, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer3->Add(btnSelectPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(300,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    checkGenerateInt = new wxCheckBox(Panel1, ID_CHECKBOX9, _("Generate interrupt"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    checkGenerateInt->SetValue(false);
    BoxSizer2->Add(checkGenerateInt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    checkEcho = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Local echo"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    checkEcho->SetValue(true);
    BoxSizer2->Add(checkEcho, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    timerPool.SetOwner(this, ID_TIMER1);
    timerPool.Start(50, false);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&TermWindow::OntextInputTextEnter);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TermWindow::OntextInputTextEnter);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TermWindow::OnbtnClearClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TermWindow::OnbtnSelectPortClick);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&TermWindow::OntimerPoolTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&TermWindow::OnClose);
    //*)

    static int CID = 0;
    CID++;

    SetName(wxString::Format( wxT("Terminal %d"), (int)CID ));
    SetTitle(GetName());

    this->cpu = cpu;
    this->portNo = -1;

    if (!this->showPortSelectDialog())
        Close();
}

TermWindow::~TermWindow()
{
    //(*Destroy(TermWindow)
    //*)
}

void TermWindow::OnbtnSelectPortClick(wxCommandEvent& event)
{
    this->showPortSelectDialog();
}

void TermWindow::set(uint8_t value)
{
    this->mutex.Lock();
    this->str = wxString(1, (wxChar)value);
    this->mutex.Unlock();
}

string TermWindow::getName()
{
    return string(GetName().mb_str());
}

bool TermWindow::showPortSelectDialog()
{
    long res;

    res = wxGetNumberFromUser(_("Select port number"),
                              _("Port:"), _("Terminal"), (long)this->portNo,
                              0, Cpu::IO_PORTS_NO-1, this);

    if ((res >= 0) && (res < (long)Cpu::IO_PORTS_NO))
    {
        if (res != this->portNo)
        {
            this->cpu->detachInput(this->in);
            this->in = this->cpu->ins[res].attach( this->getName() );

            if (this->in == NULL)
            {
                wxMessageBox(_("Port already in use!"), _("Error"),
                             wxICON_ERROR, this);
                labelPort->SetLabel(_("<none>"));
            }

            else
            {
                this->cpu->detachOutput(this);
                this->cpu->outs[res].attach(this);

                this->portNo = res;

                wxString str = wxString::Format(wxT("%d   (0x%02X)"), res, res);
                labelPort->SetLabel(str);
            }
        }

        this->updateParentWindow();
        return true;
    }

    return false;
}

void TermWindow::sendChar(wxChar ch)
{
    if (this->in != NULL)
        *this->in = (uint8_t)ch;

    if (checkGenerateInt->IsChecked())
        this->cpu->generateInt();
}

void TermWindow::updateParentWindow()
{
    MainWindow *parent = (MainWindow*)GetParent();
    if (parent != NULL)
    {
        parent->updateInInfo();
        parent->updateOutInfo();
    }
}

void TermWindow::OntextInputTextEnter(wxCommandEvent& event)
{
    wxString str = textInput->GetValue();
    textInput->Clear();

    for (unsigned int i=0; i<str.length(); ++i)
        this->sendChar(str[i]);

    if (checkEcho->IsChecked())
        textTerm->AppendText(_T("\n") + str);
}

void TermWindow::OnbtnClearClick(wxCommandEvent& event)
{
    textTerm->Clear();
}

void TermWindow::OntimerPoolTrigger(wxTimerEvent& event)
{
    this->mutex.Lock();
    textTerm->AppendText(this->str);
    this->str.clear();
    this->mutex.Unlock();
}

void TermWindow::OnClose(wxCloseEvent& event)
{
    this->cpu->detachInput(this->in);
    this->cpu->detachOutput(this);
    this->updateParentWindow();
    event.Skip();
}
