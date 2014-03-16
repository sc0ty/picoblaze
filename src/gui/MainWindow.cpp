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

	Main window - frontend
*/

#include "../wx_pch.h"
#include "MainWindow.h"
#include "AboutWindow.h"
#include "components/LedsWindow.h"
#include "components/SwitchWindow.h"
#include "components/KeyboardWindow.h"
#include "components/TermWindow.h"
#include "components/TimerWindow.h"

//(*InternalHeaders(MainWindow)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MainWindow)
const long MainWindow::ID_AUITOOLBARITEM1 = wxNewId();
const long MainWindow::ID_BTNSTART = wxNewId();
const long MainWindow::ID_BTNSTOP = wxNewId();
const long MainWindow::ID_BTNSTEP = wxNewId();
const long MainWindow::ID_BTNRESET = wxNewId();
const long MainWindow::ID_AUITOOLBAR1 = wxNewId();
const long MainWindow::ID_GRIDREG = wxNewId();
const long MainWindow::ID_GRIDRAM = wxNewId();
const long MainWindow::ID_GRIDSTACK = wxNewId();
const long MainWindow::ID_CHECKBOX1 = wxNewId();
const long MainWindow::ID_CHECKBOX2 = wxNewId();
const long MainWindow::ID_CHECKBOX3 = wxNewId();
const long MainWindow::ID_PANELFLAGS = wxNewId();
const long MainWindow::ID_GRID2 = wxNewId();
const long MainWindow::ID_GRID1 = wxNewId();
const long MainWindow::ID_GRIDPROGRAM = wxNewId();
const long MainWindow::ID_AUITOOLBARITEM2 = wxNewId();
const long MainWindow::ID_AUITOOLBARITEM3 = wxNewId();
const long MainWindow::ID_AUITOOLBARITEM4 = wxNewId();
const long MainWindow::ID_AUITOOLBARITEM5 = wxNewId();
const long MainWindow::ID_AUITOOLBARITEM6 = wxNewId();
const long MainWindow::ID_AUITOOLBAR2 = wxNewId();
const long MainWindow::idMenuLoad = wxNewId();
const long MainWindow::idMenuClearRegs = wxNewId();
const long MainWindow::idMenuClearRam = wxNewId();
const long MainWindow::idMenuClearStack = wxNewId();
const long MainWindow::idMenuClearFlags = wxNewId();
const long MainWindow::idMenuClearAll = wxNewId();
const long MainWindow::idMenuExit = wxNewId();
const long MainWindow::idMenuDec = wxNewId();
const long MainWindow::idMenuHex = wxNewId();
const long MainWindow::idMenuProgram = wxNewId();
const long MainWindow::idMenuRegs = wxNewId();
const long MainWindow::idMenuRam = wxNewId();
const long MainWindow::idMenuStack = wxNewId();
const long MainWindow::idMenuIn = wxNewId();
const long MainWindow::idMenuOut = wxNewId();
const long MainWindow::idMenuFlags = wxNewId();
const long MainWindow::idMenuToolbarSim = wxNewId();
const long MainWindow::idMenuToolbarComponents = wxNewId();
const long MainWindow::idMenuToolbars = wxNewId();
const long MainWindow::idMenuStart = wxNewId();
const long MainWindow::idMenuStop = wxNewId();
const long MainWindow::idMenuKrok = wxNewId();
const long MainWindow::idMenuReset = wxNewId();
const long MainWindow::idMenuLeds = wxNewId();
const long MainWindow::idMenuSwitches = wxNewId();
const long MainWindow::idMenuKeyboard = wxNewId();
const long MainWindow::idMenuTerminal = wxNewId();
const long MainWindow::idMenuTimer = wxNewId();
const long MainWindow::idMenuAbout = wxNewId();
const long MainWindow::ID_STATUSBAR1 = wxNewId();
const long MainWindow::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MainWindow,wxFrame)
    //(*EventTable(MainWindow)
    //*)
END_EVENT_TABLE()

MainWindow::MainWindow(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MainWindow)
    wxFlexGridSizer* FlexGridSizer1;
    wxMenuBar* menuBar;
    wxMenuItem* MenuSwitches;
    wxMenu* Menu2;
    wxMenuItem* MenuLeds;

    Create(parent, wxID_ANY, _("PicoBlaze Simulator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(900,700));
    SetMinSize(wxSize(1000,500));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("img/icon.ico"))));
    	SetIcon(FrameIcon);
    }
    auiManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    toolbarSim = new wxAuiToolBar(this, ID_AUITOOLBAR1, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    toolbarSim->AddTool(ID_AUITOOLBARITEM1, _("Load"), wxBitmap(wxImage(_T("img/open.png"))), wxNullBitmap, wxITEM_NORMAL, _("Load program"), wxEmptyString, NULL);
    toolbarSim->AddSeparator();
    toolbarSim->AddTool(ID_BTNSTART, _("Start"), wxBitmap(wxImage(_T("img/start.gif"))), wxBitmap(wxImage(_T("img/startn.gif"))), wxITEM_NORMAL, _("Start"), wxEmptyString, NULL);
    toolbarSim->AddTool(ID_BTNSTOP, _("Stop"), wxBitmap(wxImage(_T("img/stop.gif"))), wxBitmap(wxImage(_T("img/stopn.gif"))), wxITEM_NORMAL, _("Stop"), wxEmptyString, NULL);
    toolbarSim->AddTool(ID_BTNSTEP, _("Step"), wxBitmap(wxImage(_T("img/step.gif"))), wxBitmap(wxImage(_T("img/stepn.gif"))), wxITEM_NORMAL, _("Step"), wxEmptyString, NULL);
    toolbarSim->AddSeparator();
    toolbarSim->AddTool(ID_BTNRESET, _("Reset"), wxBitmap(wxImage(_T("img/reset.gif"))), wxBitmap(wxImage(_T("img/resetn.gif"))), wxITEM_NORMAL, _("Reset"), wxEmptyString, NULL);
    toolbarSim->Realize();
    auiManager->AddPane(toolbarSim, wxAuiPaneInfo().Name(_T("Main tools")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());
    gridRegs = new wxGrid(this, ID_GRIDREG, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRIDREG"));
    gridRegs->CreateGrid(18,1);
    gridRegs->SetMinSize(wxSize(110,200));
    wxFont gridRegsFont(11,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    gridRegs->SetFont(gridRegsFont);
    gridRegs->EnableEditing(true);
    gridRegs->EnableGridLines(true);
    gridRegs->SetRowLabelSize(32);
    gridRegs->SetDefaultColSize(64, true);
    gridRegs->SetColLabelValue(0, _("Value"));
    gridRegs->SetRowLabelValue(0, _("s0"));
    gridRegs->SetRowLabelValue(1, _("s1"));
    gridRegs->SetRowLabelValue(2, _("s2"));
    gridRegs->SetRowLabelValue(3, _("s3"));
    gridRegs->SetRowLabelValue(4, _("s4"));
    gridRegs->SetRowLabelValue(5, _("s5"));
    gridRegs->SetRowLabelValue(6, _("s6"));
    gridRegs->SetRowLabelValue(7, _("s7"));
    gridRegs->SetRowLabelValue(8, _("s8"));
    gridRegs->SetRowLabelValue(9, _("s9"));
    gridRegs->SetRowLabelValue(10, _("sA"));
    gridRegs->SetRowLabelValue(11, _("sB"));
    gridRegs->SetRowLabelValue(12, _("sC"));
    gridRegs->SetRowLabelValue(13, _("sD"));
    gridRegs->SetRowLabelValue(14, _("sE"));
    gridRegs->SetRowLabelValue(15, _("sF"));
    gridRegs->SetRowLabelValue(16, _("PC"));
    gridRegs->SetRowLabelValue(17, _("SP"));
    gridRegs->SetDefaultCellFont( gridRegs->GetFont() );
    gridRegs->SetDefaultCellTextColour( gridRegs->GetForegroundColour() );
    auiManager->AddPane(gridRegs, wxAuiPaneInfo().Name(_T("paneRegs")).DefaultPane().Caption(_("Registers")).CaptionVisible().PinButton().Row(1).Left().MinSize(wxSize(110,200)));
    gridRam = new wxGrid(this, ID_GRIDRAM, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRIDRAM"));
    gridRam->CreateGrid(16,4);
    gridRam->SetMinSize(wxSize(238,200));
    wxFont gridRamFont(11,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    gridRam->SetFont(gridRamFont);
    gridRam->EnableEditing(true);
    gridRam->EnableGridLines(true);
    gridRam->SetRowLabelSize(32);
    gridRam->SetDefaultColSize(48, true);
    gridRam->SetColLabelValue(0, _("00"));
    gridRam->SetColLabelValue(1, _("10"));
    gridRam->SetColLabelValue(2, _("20"));
    gridRam->SetColLabelValue(3, _("30"));
    gridRam->SetRowLabelValue(0, _("0"));
    gridRam->SetRowLabelValue(1, _("1"));
    gridRam->SetRowLabelValue(2, _("2"));
    gridRam->SetRowLabelValue(3, _("3"));
    gridRam->SetRowLabelValue(4, _("4"));
    gridRam->SetRowLabelValue(5, _("5"));
    gridRam->SetRowLabelValue(6, _("6"));
    gridRam->SetRowLabelValue(7, _("7"));
    gridRam->SetRowLabelValue(8, _("8"));
    gridRam->SetRowLabelValue(9, _("9"));
    gridRam->SetRowLabelValue(10, _("A"));
    gridRam->SetRowLabelValue(11, _("B"));
    gridRam->SetRowLabelValue(12, _("C"));
    gridRam->SetRowLabelValue(13, _("D"));
    gridRam->SetRowLabelValue(14, _("E"));
    gridRam->SetRowLabelValue(15, _("F"));
    gridRam->SetDefaultCellFont( gridRam->GetFont() );
    gridRam->SetDefaultCellTextColour( gridRam->GetForegroundColour() );
    auiManager->AddPane(gridRam, wxAuiPaneInfo().Name(_T("paneRam")).DefaultPane().Caption(_("RAM")).CaptionVisible().PinButton().Row(2).Left().MinSize(wxSize(238,200)));
    gridStack = new wxGrid(this, ID_GRIDSTACK, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRIDSTACK"));
    gridStack->CreateGrid(31,1);
    gridStack->SetMinSize(wxSize(110,200));
    wxFont gridStackFont(11,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    gridStack->SetFont(gridStackFont);
    gridStack->EnableEditing(true);
    gridStack->EnableGridLines(true);
    gridStack->SetRowLabelSize(32);
    gridStack->SetDefaultColSize(64, true);
    gridStack->SetColLabelValue(0, _("Value"));
    gridStack->SetDefaultCellFont( gridStack->GetFont() );
    gridStack->SetDefaultCellTextColour( gridStack->GetForegroundColour() );
    auiManager->AddPane(gridStack, wxAuiPaneInfo().Name(_T("paneStack")).DefaultPane().Caption(_("Stack")).CaptionVisible().PinButton().Row(3).Left().MinSize(wxSize(110,200)));
    panelFlags = new wxPanel(this, ID_PANELFLAGS, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELFLAGS"));
    panelFlags->SetMinSize(wxSize(80,26));
    FlexGridSizer1 = new wxFlexGridSizer(0, 0, 0, 0);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    checkCF = new wxCheckBox(panelFlags, ID_CHECKBOX1, _("Carry Flag"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    checkCF->SetValue(false);
    FlexGridSizer1->Add(checkCF, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    checkZF = new wxCheckBox(panelFlags, ID_CHECKBOX2, _("Zero Flag"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    checkZF->SetValue(false);
    FlexGridSizer1->Add(checkZF, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    checkIE = new wxCheckBox(panelFlags, ID_CHECKBOX3, _("Interrupt Enable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    checkIE->SetValue(false);
    FlexGridSizer1->Add(checkIE, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    panelFlags->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(panelFlags);
    FlexGridSizer1->SetSizeHints(panelFlags);
    auiManager->AddPane(panelFlags, wxAuiPaneInfo().Name(_T("paneFlags")).DefaultPane().Caption(_("Flagi")).CaptionVisible().PinButton().Bottom().MinSize(wxSize(80,26)));
    gridOut = new wxGrid(this, ID_GRID2, wxDefaultPosition, wxSize(220,-1), 0, _T("ID_GRID2"));
    gridOut->CreateGrid(256,2);
    gridOut->SetMinSize(wxSize(120,200));
    gridOut->EnableEditing(false);
    gridOut->EnableGridLines(true);
    gridOut->SetRowLabelSize(32);
    gridOut->SetDefaultColSize(64, true);
    gridOut->SetColLabelValue(0, _("Value"));
    gridOut->SetColLabelValue(1, _("Devices"));
    gridOut->SetDefaultCellFont( gridOut->GetFont() );
    gridOut->SetDefaultCellTextColour( gridOut->GetForegroundColour() );
    auiManager->AddPane(gridOut, wxAuiPaneInfo().Name(_T("paneOut")).DefaultPane().Caption(_("Output")).CaptionVisible().PinButton().Right().BestSize(wxSize(220,-1)).MinSize(wxSize(120,200)));
    gridIn = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(220,-1), 0, _T("ID_GRID1"));
    gridIn->CreateGrid(256,2);
    gridIn->SetMinSize(wxSize(120,200));
    gridIn->EnableEditing(false);
    gridIn->EnableGridLines(true);
    gridIn->SetRowLabelSize(32);
    gridIn->SetDefaultColSize(64, true);
    gridIn->SetColLabelValue(0, _("Value"));
    gridIn->SetColLabelValue(1, _("Devices"));
    gridIn->SetDefaultCellFont( gridIn->GetFont() );
    gridIn->SetDefaultCellTextColour( gridIn->GetForegroundColour() );
    auiManager->AddPane(gridIn, wxAuiPaneInfo().Name(_T("paneIn")).DefaultPane().Caption(_("Inputs")).CaptionVisible().PinButton().Row(1).Right().BestSize(wxSize(220,-1)).MinSize(wxSize(120,200)));
    gridProgram = new wxGrid(this, ID_GRIDPROGRAM, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRIDPROGRAM"));
    gridProgram->CreateGrid(1024,2);
    gridProgram->SetMinSize(wxSize(120,200));
    wxFont gridProgramFont(11,wxTELETYPE,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Courier 10 Pitch"),wxFONTENCODING_DEFAULT);
    gridProgram->SetFont(gridProgramFont);
    gridProgram->EnableEditing(true);
    gridProgram->EnableGridLines(true);
    gridProgram->SetRowLabelSize(30);
    gridProgram->SetDefaultColSize(80, true);
    gridProgram->SetColLabelValue(0, _("Opcode"));
    gridProgram->SetColLabelValue(1, _("Instruction"));
    gridProgram->SetDefaultCellFont( gridProgram->GetFont() );
    gridProgram->SetDefaultCellTextColour( gridProgram->GetForegroundColour() );
    auiManager->AddPane(gridProgram, wxAuiPaneInfo().Name(_T("paneProgram")).DefaultPane().Caption(_("Program")).CaptionVisible().PinButton().Center().MinSize(wxSize(120,200)));
    toolbarComponents = new wxAuiToolBar(this, ID_AUITOOLBAR2, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    toolbarComponents->AddTool(ID_AUITOOLBARITEM2, _("Leds"), wxBitmap(wxImage(_T("img/leds.png"))), wxNullBitmap, wxITEM_NORMAL, _("LEDs"), wxEmptyString, NULL);
    toolbarComponents->AddTool(ID_AUITOOLBARITEM3, _("Switches"), wxBitmap(wxImage(_T("img/switches.png"))), wxNullBitmap, wxITEM_NORMAL, _("Switches"), wxEmptyString, NULL);
    toolbarComponents->AddTool(ID_AUITOOLBARITEM4, _("Keyboard"), wxBitmap(wxImage(_T("img/keyboard.png"))), wxNullBitmap, wxITEM_NORMAL, _("Keyboard"), wxEmptyString, NULL);
    toolbarComponents->AddTool(ID_AUITOOLBARITEM5, _("Terminal"), wxBitmap(wxImage(_T("img/terminal.png"))), wxNullBitmap, wxITEM_NORMAL, _("Terminal"), wxEmptyString, NULL);
    toolbarComponents->AddTool(ID_AUITOOLBARITEM6, _("Timer"), wxBitmap(wxImage(_T("img/timer.png"))), wxNullBitmap, wxITEM_NORMAL, _("Timer"), wxEmptyString, NULL);
    toolbarComponents->Realize();
    auiManager->AddPane(toolbarComponents, wxAuiPaneInfo().Name(_T("Devices")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Position(1).Top().Gripper());
    auiManager->Update();
    menuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuLoad = new wxMenuItem(Menu1, idMenuLoad, _("Open"), wxEmptyString, wxITEM_NORMAL);
    MenuLoad->SetBitmap(wxBitmap(wxImage(_T("img/open.png"))));
    Menu1->Append(MenuLoad);
    Menu1->AppendSeparator();
    MenuClearRegs = new wxMenuItem(Menu1, idMenuClearRegs, _("Clear registers"), wxEmptyString, wxITEM_NORMAL);
    MenuClearRegs->SetBitmap(wxBitmap(wxImage(_T("img/clear.png"))));
    Menu1->Append(MenuClearRegs);
    MenuClearRam = new wxMenuItem(Menu1, idMenuClearRam, _("Clear RAM"), wxEmptyString, wxITEM_NORMAL);
    MenuClearRam->SetBitmap(wxBitmap(wxImage(_T("img/clear.png"))));
    Menu1->Append(MenuClearRam);
    MenuClearStack = new wxMenuItem(Menu1, idMenuClearStack, _("Clear stack"), wxEmptyString, wxITEM_NORMAL);
    MenuClearStack->SetBitmap(wxBitmap(wxImage(_T("img/clear.png"))));
    Menu1->Append(MenuClearStack);
    MenuClearFlags = new wxMenuItem(Menu1, idMenuClearFlags, _("Clear flags"), wxEmptyString, wxITEM_NORMAL);
    MenuClearFlags->SetBitmap(wxBitmap(wxImage(_T("img/clear.png"))));
    Menu1->Append(MenuClearFlags);
    MenuClearAll = new wxMenuItem(Menu1, idMenuClearAll, _("Clear all"), wxEmptyString, wxITEM_NORMAL);
    MenuClearAll->SetBitmap(wxBitmap(wxImage(_T("img/clearall.png"))));
    Menu1->Append(MenuClearAll);
    Menu1->AppendSeparator();
    MenuExit = new wxMenuItem(Menu1, idMenuExit, _("Exit"), wxEmptyString, wxITEM_NORMAL);
    MenuExit->SetBitmap(wxBitmap(wxImage(_T("img/exit.png"))));
    Menu1->Append(MenuExit);
    menuBar->Append(Menu1, _("File"));
    Menu4 = new wxMenu();
    MenuDec = new wxMenuItem(Menu4, idMenuDec, _("Decimal values"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuDec);
    MenuHex = new wxMenuItem(Menu4, idMenuHex, _("Hexadecimal values"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuHex);
    Menu4->AppendSeparator();
    MenuProgram = new wxMenuItem(Menu4, idMenuProgram, _("Program"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuProgram);
    MenuProgram->Check(true);
    MenuRegs = new wxMenuItem(Menu4, idMenuRegs, _("Registers"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuRegs);
    MenuRegs->Check(true);
    MenuRam = new wxMenuItem(Menu4, idMenuRam, _("RAM"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuRam);
    MenuRam->Check(true);
    MenuStack = new wxMenuItem(Menu4, idMenuStack, _("Stack"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuStack);
    MenuStack->Check(true);
    MenuIn = new wxMenuItem(Menu4, idMenuIn, _("Inputs"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuIn);
    MenuIn->Check(true);
    MenuOut = new wxMenuItem(Menu4, idMenuOut, _("Outputs"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuOut);
    MenuOut->Check(true);
    MenuFlags = new wxMenuItem(Menu4, idMenuFlags, _("Flags"), wxEmptyString, wxITEM_CHECK);
    Menu4->Append(MenuFlags);
    MenuFlags->Check(true);
    MenuItem2 = new wxMenu();
    MenuToolbarSim = new wxMenuItem(MenuItem2, idMenuToolbarSim, _("Simulation"), wxEmptyString, wxITEM_CHECK);
    MenuItem2->Append(MenuToolbarSim);
    MenuToolbarSim->Check(true);
    MenuToolbarComponents = new wxMenuItem(MenuItem2, idMenuToolbarComponents, _("Devices"), wxEmptyString, wxITEM_CHECK);
    MenuItem2->Append(MenuToolbarComponents);
    MenuToolbarComponents->Check(true);
    Menu4->Append(idMenuToolbars, _("Toolbars"), MenuItem2, wxEmptyString);
    menuBar->Append(Menu4, _("View"));
    Menu3 = new wxMenu();
    MenuStart = new wxMenuItem(Menu3, idMenuStart, _("Start"), wxEmptyString, wxITEM_NORMAL);
    MenuStart->SetBitmap(wxBitmap(wxImage(_T("img/start.gif"))));
    Menu3->Append(MenuStart);
    MenuStop = new wxMenuItem(Menu3, idMenuStop, _("Stop"), wxEmptyString, wxITEM_NORMAL);
    MenuStop->SetBitmap(wxBitmap(wxImage(_T("img/stop.gif"))));
    Menu3->Append(MenuStop);
    MenuStep = new wxMenuItem(Menu3, idMenuKrok, _("Step"), wxEmptyString, wxITEM_NORMAL);
    MenuStep->SetBitmap(wxBitmap(wxImage(_T("img/step.gif"))));
    Menu3->Append(MenuStep);
    Menu3->AppendSeparator();
    MenuReset = new wxMenuItem(Menu3, idMenuReset, _("Reset"), wxEmptyString, wxITEM_NORMAL);
    MenuReset->SetBitmap(wxBitmap(wxImage(_T("img/reset.gif"))));
    Menu3->Append(MenuReset);
    menuBar->Append(Menu3, _("Simulation"));
    Menu2 = new wxMenu();
    MenuLeds = new wxMenuItem(Menu2, idMenuLeds, _("LEDs"), wxEmptyString, wxITEM_NORMAL);
    MenuLeds->SetBitmap(wxBitmap(wxImage(_T("img/leds.png"))));
    Menu2->Append(MenuLeds);
    MenuSwitches = new wxMenuItem(Menu2, idMenuSwitches, _("Switches"), wxEmptyString, wxITEM_NORMAL);
    MenuSwitches->SetBitmap(wxBitmap(wxImage(_T("img/switches.png"))));
    Menu2->Append(MenuSwitches);
    MenuKeyboard = new wxMenuItem(Menu2, idMenuKeyboard, _("Keyboard"), wxEmptyString, wxITEM_NORMAL);
    MenuKeyboard->SetBitmap(wxBitmap(wxImage(_T("img/keyboard.png"))));
    Menu2->Append(MenuKeyboard);
    MenuTerminal = new wxMenuItem(Menu2, idMenuTerminal, _("Terminal"), wxEmptyString, wxITEM_NORMAL);
    MenuTerminal->SetBitmap(wxBitmap(wxImage(_T("img/terminal.png"))));
    Menu2->Append(MenuTerminal);
    MenuTimer = new wxMenuItem(Menu2, idMenuTimer, _("Timer"), wxEmptyString, wxITEM_NORMAL);
    MenuTimer->SetBitmap(wxBitmap(wxImage(_T("img/timer.png"))));
    Menu2->Append(MenuTimer);
    menuBar->Append(Menu2, _("Devices"));
    Menu5 = new wxMenu();
    MenuAbout = new wxMenuItem(Menu5, idMenuAbout, _("About program"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(MenuAbout);
    menuBar->Append(Menu5, _("Help"));
    SetMenuBar(menuBar);
    statusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { 120, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    statusBar->SetFieldsCount(2,__wxStatusBarWidths_1);
    statusBar->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(statusBar);
    dlgLoadHex = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("Program files|*.hex|All files|*.*"), wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    timerMips.SetOwner(this, ID_TIMER1);

    Connect(ID_AUITOOLBARITEM1,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnMenuLoadSelected);
    Connect(ID_BTNSTART,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnStartClick);
    Connect(ID_BTNSTOP,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnStopClick);
    Connect(ID_BTNSTEP,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnStepClick);
    Connect(ID_BTNRESET,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnResetClick);
    Connect(ID_GRIDREG,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&MainWindow::OngridRegsCellChange);
    Connect(ID_GRIDRAM,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&MainWindow::OngridRamCellChange);
    Connect(ID_GRIDSTACK,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&MainWindow::OngridStackCellChange);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MainWindow::OncheckCFClick);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MainWindow::OncheckZFClick);
    Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&MainWindow::OncheckIEClick);
    Connect(ID_GRIDPROGRAM,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&MainWindow::OngridProgramCellChange);
    Connect(ID_AUITOOLBARITEM2,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnMenuDiodySelected);
    Connect(ID_AUITOOLBARITEM3,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnMenuSwitchesSelected);
    Connect(ID_AUITOOLBARITEM4,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnKeyboardClick);
    Connect(ID_AUITOOLBARITEM5,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnTerminalClick);
    Connect(ID_AUITOOLBARITEM6,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&MainWindow::OnbtnTimerClick);
    auiManager->Connect(wxEVT_AUI_PANE_CLOSE,(wxObjectEventFunction)&MainWindow::OnauiManagerPaneClose,0,this);
    Connect(idMenuLoad,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuLoadSelected);
    Connect(idMenuClearRegs,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuClearRegsSelected);
    Connect(idMenuClearRam,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuClearRamSelected);
    Connect(idMenuClearStack,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuClearStackSelected);
    Connect(idMenuClearFlags,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuClearFlagsSelected);
    Connect(idMenuClearAll,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuClearAllSelected);
    Connect(idMenuExit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuExitSelected);
    Connect(idMenuDec,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuDecSelected);
    Connect(idMenuHex,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuHexSelected);
    Connect(idMenuProgram,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuProgramSelected);
    Connect(idMenuRegs,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuRegsSelected);
    Connect(idMenuRam,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuRamSelected);
    Connect(idMenuStack,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuStackSelected);
    Connect(idMenuIn,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuInSelected);
    Connect(idMenuOut,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuOutSelected);
    Connect(idMenuFlags,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuFlagsSelected);
    Connect(idMenuToolbarSim,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuToolbarSimSelected);
    Connect(idMenuToolbarComponents,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuToolbarComponentsSelected);
    Connect(idMenuStart,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnbtnStartClick);
    Connect(idMenuStop,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnbtnStopClick);
    Connect(idMenuKrok,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnbtnStepClick);
    Connect(idMenuReset,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnbtnResetClick);
    Connect(idMenuLeds,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuDiodySelected);
    Connect(idMenuSwitches,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuSwitchesSelected);
    Connect(idMenuKeyboard,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnbtnKeyboardClick);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainWindow::OnMenuAboutSelected);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&MainWindow::OntimerMipsTrigger);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&MainWindow::OnClose);
    //*)

    unsigned int i;
    wxColour color;

    Maximize();

    hexFormat = true;
    MenuHex->Check();

    cpuThread.setCpu(&this->cpu);
    stopCpu();

    gridRam->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    gridRegs->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    gridStack->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);

    gridProgram->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    gridProgram->SetColSize(1, 180);

    gridIn->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    gridIn->SetColSize(1, 120);

    gridOut->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    gridOut->SetColSize(1, 120);

    color = wxColour(255, 200, 160);

    for (i=0; i<Cpu::REGS_NO; ++i)
        gridRegs->SetCellBackgroundColour(i, 0, color);

    gridRegs->SetCellBackgroundColour(16, 0, *wxLIGHT_GREY);
    gridRegs->SetCellBackgroundColour(17, 0, *wxLIGHT_GREY);

    color = wxColour(255, 200, 255);

    for (i=0; i<Cpu::RAM_SIZE; ++i)
        gridRam->SetCellBackgroundColour(i%16, i/16, color);

    for (i=0; i<Cpu::STACK_SIZE; ++i)
        gridStack->SetRowLabelValue(i, this->uintToStr(i));

    for (i=0; i<Cpu::INSTRUCTIONS_NO; ++i)
    {
        gridProgram->SetRowLabelValue(i, this->uintToStr(i, true));
        gridProgram->SetCellAlignment(wxALIGN_LEFT, i, 1);
        gridProgram->SetReadOnly(i, 1);
    }

    wxFont font(11, wxTELETYPE, wxFONTSTYLE_NORMAL, wxNORMAL, false,
                _T("Courier 10 Pitch"), wxFONTENCODING_DEFAULT);

    color = wxColour(160, 255, 160);

    for (i=0; i<Cpu::IO_PORTS_NO; ++i)
    {
        gridIn->SetRowLabelValue(i, this->uintToStr(i));
        gridIn->SetCellFont(i, 0, font);
        gridIn->SetCellAlignment(wxALIGN_LEFT, i, 1);
        gridIn->SetCellBackgroundColour(i, 0, color);
        gridIn->SetCellBackgroundColour(i, 1, color);

        gridOut->SetRowLabelValue(i, this->uintToStr(i));
        gridOut->SetCellFont(i, 0, font);
        gridOut->SetCellAlignment(wxALIGN_LEFT, i, 1);
        gridOut->SetCellBackgroundColour(i, 0, color);
        gridOut->SetCellBackgroundColour(i, 1, color);
    }

    this->updateCpuInfo();
    this->updateProgramInfo();

    Maximize();
    auiManager->Update();
    Layout();
}

MainWindow::~MainWindow()
{
    //(*Destroy(MainWindow)
    //*)
}

void MainWindow::OnbtnStartClick(wxCommandEvent& event)
{
    this->startCpu();
}

void MainWindow::OnbtnStopClick(wxCommandEvent& event)
{
    this->stopCpu();
}

void MainWindow::OntimerMipsTrigger(wxTimerEvent& event)
{
    if (this->cpuThread.IsRunning())
    {
        float mips = this->cpuThread.getCounter();
        this->updateMipsCounter(mips);
    }
}

void MainWindow::OnbtnResetClick(wxCommandEvent& event)
{
    this->cpu.reset();

    if (!this->cpuThread.IsRunning())
        this->updateCpuInfo();
}

void MainWindow::OnMenuDiodySelected(wxCommandEvent& event)
{
    LedsWindow *component = new LedsWindow(this, &this->cpu);
    this->addComponent(component);
}

void MainWindow::OnMenuSwitchesSelected(wxCommandEvent& event)
{
    SwitchWindow *component = new SwitchWindow(this, &this->cpu);
    this->addComponent(component);
}

void MainWindow::OnbtnKeyboardClick(wxCommandEvent& event)
{
    KeyboardWindow *component = new KeyboardWindow(this, &this->cpu);
    this->addComponent(component);
}

void MainWindow::OnbtnTerminalClick(wxCommandEvent& event)
{
    TermWindow *component = new TermWindow(this, &this->cpu);
    this->addComponent(component);
}

void MainWindow::OnbtnTimerClick(wxCommandEvent& event)
{
    TimerWindow *component = new TimerWindow(this, &this->cpu);
    this->addComponent(component);
}

void MainWindow::OnClose(wxCloseEvent& event)
{
    event.Skip();
}

void MainWindow::OnMenuLoadSelected(wxCommandEvent& event)
{
    this->showLoadProgramDialog();
}

void MainWindow::OnbtnStepClick(wxCommandEvent& event)
{
    this->step();
}

void MainWindow::OngridRegsCellChange(wxGridEvent& event)
{
    if (event.GetCol() == 0)
        this->updateGridRegsCell(event.GetRow());

    this->updateCpuInfo();
}

void MainWindow::OngridRamCellChange(wxGridEvent& event)
{
    this->updateGridRamCell(event.GetCol(), event.GetRow());
    this->updateCpuInfo();
}

void MainWindow::OngridStackCellChange(wxGridEvent& event)
{
    if (event.GetCol() == 0)
        this->updateGridStackCell(event.GetRow());

    this->updateCpuInfo();
}

void MainWindow::OngridProgramCellChange(wxGridEvent& event)
{
    if (event.GetCol() == 0)
        this->updateGridProgramCell(event.GetRow());

    this->updateProgramInfo();
}

void MainWindow::OncheckCFClick(wxCommandEvent& event)
{
    this->cpu.setCF(event.IsChecked());
}

void MainWindow::OncheckZFClick(wxCommandEvent& event)
{
    this->cpu.setZF(event.IsChecked());
}

void MainWindow::OncheckIEClick(wxCommandEvent& event)
{
    this->cpu.setIE(event.IsChecked());
}

void MainWindow::OnMenuHexSelected(wxCommandEvent& event)
{
    this->hexFormat = true;//event.IsChecked();
    this->updateCpuInfo();
}

void MainWindow::OnMenuDecSelected(wxCommandEvent& event)
{
    this->hexFormat = false;
    this->updateCpuInfo();
}

void MainWindow::OnMenuProgramSelected(wxCommandEvent& event)
{
    this->showPane(this->gridProgram, event.IsChecked());
}

void MainWindow::OnMenuRegsSelected(wxCommandEvent& event)
{
    this->showPane(this->gridRegs, event.IsChecked());
}

void MainWindow::OnMenuFlagsSelected(wxCommandEvent& event)
{
    this->showPane(this->panelFlags, event.IsChecked());
}

void MainWindow::OnMenuRamSelected(wxCommandEvent& event)
{
    this->showPane(this->gridRam, event.IsChecked());
}

void MainWindow::OnMenuStackSelected(wxCommandEvent& event)
{
    this->showPane(this->gridStack, event.IsChecked());
}

void MainWindow::OnMenuInSelected(wxCommandEvent& event)
{
    this->showPane(this->gridIn, event.IsChecked());
}

void MainWindow::OnMenuOutSelected(wxCommandEvent& event)
{
    this->showPane(this->gridOut, event.IsChecked());
}

void MainWindow::OnMenuToolbarSimSelected(wxCommandEvent& event)
{
    this->showPane(this->toolbarSim, event.IsChecked());
}

void MainWindow::OnMenuToolbarComponentsSelected(wxCommandEvent& event)
{
    this->showPane(this->toolbarComponents, event.IsChecked());
}

void MainWindow::OnauiManagerPaneClose(wxAuiManagerEvent& event)
{
    wxAuiPaneInfo *pane = event.GetPane();

    if (pane->IsOk())
    {
        if (pane == &this->auiManager->GetPane(this->gridProgram))
            this->MenuProgram->Check(false);

        else if (pane == &this->auiManager->GetPane(this->gridRegs))
            this->MenuRegs->Check(false);

        else if (pane == &this->auiManager->GetPane(this->panelFlags))
            this->MenuFlags->Check(false);

        else if (pane == &this->auiManager->GetPane(this->gridRam))
            this->MenuRam->Check(false);

        else if (pane == &this->auiManager->GetPane(this->gridStack))
            this->MenuStack->Check(false);

        else if (pane == &this->auiManager->GetPane(this->gridIn))
            this->MenuIn->Check(false);

        else if (pane == &this->auiManager->GetPane(this->gridOut))
            this->MenuOut->Check(false);

        else if (pane == &this->auiManager->GetPane(this->toolbarComponents))
            this->MenuToolbarComponents->Check(false);

        else if (pane == &this->auiManager->GetPane(this->toolbarComponents))
            this->MenuToolbarComponents->Check(false);
    }
}

void MainWindow::OnMenuClearRegsSelected(wxCommandEvent& event)
{
    this->cpu.clearRegisters();
    this->cpu.setPC(0);
    this->cpu.setSP(0);
    this->updateCpuInfo();
    this->updateProgramInfo();
}

void MainWindow::OnMenuClearRamSelected(wxCommandEvent& event)
{
    this->cpu.clearRam();
    this->updateCpuInfo();
}

void MainWindow::OnMenuClearStackSelected(wxCommandEvent& event)
{
    this->cpu.clearStack();
    this->updateCpuInfo();
}

void MainWindow::OnMenuClearFlagsSelected(wxCommandEvent& event)
{
    this->cpu.clearFlags();
    this->updateCpuInfo();
}

void MainWindow::OnMenuClearAllSelected(wxCommandEvent& event)
{
    this->cpu.clear();
    this->updateCpuInfo();
    this->updateProgramInfo();
}

void MainWindow::OnMenuExitSelected(wxCommandEvent& event)
{
    Close();
}


void MainWindow::OnMenuAboutSelected(wxCommandEvent& event)
{
    AboutWindow *aboutWindow = new AboutWindow(this);
    aboutWindow->MakeModal();
    aboutWindow->Show();
}
