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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//(*Headers(MainWindow)
#include <wx/grid.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/timer.h>
//*)

#include "../cpu/cpu.h"
#include "CpuThread.h"

class MainWindow: public wxFrame
{
public:
    MainWindow(wxWindow* parent, wxWindowID id = -1);
    ~MainWindow();

    void updateInInfo();
    void updateOutInfo();

private:
    void startCpu();
    void stopCpu();
    void step();
    void updateMipsCounter(int mips);

    void disableControls();
    void enableControls();

    wxString &uintToStr(unsigned int i, bool align=false);
    unsigned int strToUint(const wxString &str);

    void updateCpuInfo();
    void updateProgramInfo();
    void selectProgramPos(int pos);

    void showLoadProgramDialog();
    void addComponent(wxWindow* component);

    void updateGridRegsCell(int row);
    void updateGridRamCell(int col, int row);
    void updateGridStackCell(int row);
    void updateGridProgramCell(int row);

    void showPane(wxWindow *window, bool show=true);

private:
    Cpu cpu;
    CpuThread cpuThread;

    bool hexFormat;
    wxString str;

    //(*Handlers(MainWindow)
    void OnQuit(wxCommandEvent& event);
    void OnbtnStartClick(wxCommandEvent& event);
    void OnbtnStopClick(wxCommandEvent& event);
    void OntimerMipsTrigger(wxTimerEvent& event);
    void OnbtnResetClick(wxCommandEvent& event);
    void OnMenuDiodySelected(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnMenuSwitchesSelected(wxCommandEvent& event);
    void OnMenuLoadSelected(wxCommandEvent& event);
    void OnbtnStepClick(wxCommandEvent& event);
    void OngridRegsCellChange(wxGridEvent& event);
    void OncheckCFClick(wxCommandEvent& event);
    void OncheckZFClick(wxCommandEvent& event);
    void OncheckIEClick(wxCommandEvent& event);
    void OngridRamCellChange(wxGridEvent& event);
    void OngridStackCellChange(wxGridEvent& event);
    void OnMenuHexSelected(wxCommandEvent& event);
    void OngridProgramCellChange(wxGridEvent& event);
    void OnMenuProgramSelected(wxCommandEvent& event);
    void OnMenuRegsSelected(wxCommandEvent& event);
    void OnMenuFlagsSelected(wxCommandEvent& event);
    void OnMenuRamSelected(wxCommandEvent& event);
    void OnMenuStackSelected(wxCommandEvent& event);
    void OnauiManagerPaneClose(wxAuiManagerEvent& event);
    void OnMenuDecSelected(wxCommandEvent& event);
    void OnMenuClearRegsSelected(wxCommandEvent& event);
    void OnMenuClearRamSelected(wxCommandEvent& event);
    void OnMenuClearStackSelected(wxCommandEvent& event);
    void OnMenuClearFlagsSelected(wxCommandEvent& event);
    void OnMenuClearAllSelected(wxCommandEvent& event);
    void OnMenuExitSelected(wxCommandEvent& event);
    void OnMenuToolbarSimSelected(wxCommandEvent& event);
    void OnMenuToolbarComponentsSelected(wxCommandEvent& event);
    void OnbtnKeyboardClick(wxCommandEvent& event);
    void OnbtnTerminalClick(wxCommandEvent& event);
    void OnbtnTimerClick(wxCommandEvent& event);
    void OnMenuOutSelected(wxCommandEvent& event);
    void OnMenuInSelected(wxCommandEvent& event);
    void OnMenuAboutSelected(wxCommandEvent& event);
    //*)

    //(*Identifiers(MainWindow)
    static const long ID_AUITOOLBARITEM1;
    static const long ID_BTNSTART;
    static const long ID_BTNSTOP;
    static const long ID_BTNSTEP;
    static const long ID_BTNRESET;
    static const long ID_AUITOOLBAR1;
    static const long ID_GRIDREG;
    static const long ID_GRIDRAM;
    static const long ID_GRIDSTACK;
    static const long ID_CHECKBOX1;
    static const long ID_CHECKBOX2;
    static const long ID_CHECKBOX3;
    static const long ID_PANELFLAGS;
    static const long ID_GRID2;
    static const long ID_GRID1;
    static const long ID_GRIDPROGRAM;
    static const long ID_AUITOOLBARITEM2;
    static const long ID_AUITOOLBARITEM3;
    static const long ID_AUITOOLBARITEM4;
    static const long ID_AUITOOLBARITEM5;
    static const long ID_AUITOOLBARITEM6;
    static const long ID_AUITOOLBAR2;
    static const long idMenuLoad;
    static const long idMenuClearRegs;
    static const long idMenuClearRam;
    static const long idMenuClearStack;
    static const long idMenuClearFlags;
    static const long idMenuClearAll;
    static const long idMenuExit;
    static const long idMenuDec;
    static const long idMenuHex;
    static const long idMenuProgram;
    static const long idMenuRegs;
    static const long idMenuRam;
    static const long idMenuStack;
    static const long idMenuIn;
    static const long idMenuOut;
    static const long idMenuFlags;
    static const long idMenuToolbarSim;
    static const long idMenuToolbarComponents;
    static const long idMenuToolbars;
    static const long idMenuStart;
    static const long idMenuStop;
    static const long idMenuKrok;
    static const long idMenuReset;
    static const long idMenuLeds;
    static const long idMenuSwitches;
    static const long idMenuKeyboard;
    static const long idMenuTerminal;
    static const long idMenuTimer;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_TIMER1;
    //*)

    //(*Declarations(MainWindow)
    wxMenuItem* MenuFlags;
    wxCheckBox* checkCF;
    wxCheckBox* checkIE;
    wxMenuItem* MenuClearStack;
    wxMenu* Menu5;
    wxMenuItem* MenuRam;
    wxMenuItem* MenuTimer;
    wxStatusBar* statusBar;
    wxMenu* Menu1;
    wxMenuItem* MenuExit;
    wxMenuItem* MenuDec;
    wxGrid* gridRegs;
    wxMenu* Menu3;
    wxMenuItem* MenuReset;
    wxGrid* gridProgram;
    wxMenuItem* MenuClearAll;
    wxMenuItem* MenuTerminal;
    wxGrid* gridStack;
    wxMenuItem* MenuClearRegs;
    wxAuiToolBar* toolbarComponents;
    wxAuiManager* auiManager;
    wxMenuItem* MenuStep;
    wxAuiToolBar* toolbarSim;
    wxMenuItem* MenuClearFlags;
    wxMenuItem* MenuRegs;
    wxTimer timerMips;
    wxMenuItem* MenuToolbarComponents;
    wxGrid* gridIn;
    wxMenuItem* MenuKeyboard;
    wxGrid* gridRam;
    wxFileDialog* dlgLoadHex;
    wxMenu* MenuItem2;
    wxMenuItem* MenuLoad;
    wxMenu* Menu4;
    wxMenuItem* MenuHex;
    wxGrid* gridOut;
    wxMenuItem* MenuIn;
    wxMenuItem* MenuStack;
    wxMenuItem* MenuProgram;
    wxCheckBox* checkZF;
    wxMenuItem* MenuStart;
    wxMenuItem* MenuClearRam;
    wxPanel* panelFlags;
    wxMenuItem* MenuToolbarSim;
    wxMenuItem* MenuStop;
    wxMenuItem* MenuOut;
    wxMenuItem* MenuAbout;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // MAINWINDOW_H
