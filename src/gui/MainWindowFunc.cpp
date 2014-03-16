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

	Main window - backend
*/

#include "../wx_pch.h"
#include "MainWindow.h"
#include "../cpu/disasm.h"

void MainWindow::startCpu()
{
    if (this->cpuThread.IsPaused())
        this->cpuThread.Resume();
    else if (!this->cpuThread.IsAlive())
        this->cpuThread.Run();

    this->disableControls();
    this->updateMipsCounter(0);

    if (!timerMips.IsRunning())
        timerMips.Start(1000);
}

void MainWindow::stopCpu()
{
    if (timerMips.IsRunning())
        timerMips.Stop();

    if (this->cpuThread.IsRunning())
        this->cpuThread.Pause();

    this->updateCpuInfo();
    this->enableControls();

    statusBar->SetStatusText(_("STOP"));
}

void MainWindow::updateMipsCounter(int mips)
{
    float counter = (float)mips / 1000000;
    wxString str = wxString::Format( wxT("%0.2f MIPS"), (float)counter );
    statusBar->SetStatusText(str);
}

wxString &MainWindow::uintToStr(unsigned int i, bool align)
{
    if (this->hexFormat)
    {
        if (align)
            this->str = wxString::Format( wxT("%03X"), (unsigned int)i );
        else
            this->str = wxString::Format( wxT("%02X"), (unsigned int)i );
    }
    else
    {
        this->str = wxString::Format( wxT("%d"), (unsigned int)i );
    }

    return this->str;
}

void MainWindow::disableControls()
{
    toolbarSim->EnableTool(ID_BTNSTART, false);
    toolbarSim->EnableTool(ID_BTNSTEP, false);
    toolbarSim->EnableTool(ID_BTNSTOP, true);
    toolbarSim->Realize();

    MenuStart->Enable(false);
    MenuStep->Enable(false);
    MenuStop->Enable(true);

    gridRegs->Disable();
    gridRam->Disable();
    gridStack->Disable();
    panelFlags->Disable();

    this->selectProgramPos(-1);
}

void MainWindow::enableControls()
{
    toolbarSim->EnableTool(ID_BTNSTART, true);
    toolbarSim->EnableTool(ID_BTNSTEP, true);
    toolbarSim->EnableTool(ID_BTNSTOP, false);
    toolbarSim->Realize();

    MenuStart->Enable(true);
    MenuStep->Enable(true);
    MenuStop->Enable(false);

    gridRegs->Enable();
    gridRam->Enable();
    gridStack->Enable();
    panelFlags->Enable();
}

unsigned int MainWindow::strToUint(const wxString &str)
{
    unsigned long val;

    if (this->hexFormat)
    {
        if (str.ToULong(&val, 16))
            return (unsigned int)val;
    }
    else
    {
        if (str.ToULong(&val))
            return (unsigned int)val;
    }

    throw new exception;
}

void MainWindow::updateCpuInfo()
{
    unsigned int i;

    unsigned int pc = this->cpu.getPC();
    unsigned int sp = this->cpu.getSP();

    for (i=0; i<Cpu::REGS_NO; ++i)
        gridRegs->SetCellValue(i, 0, uintToStr( this->cpu.getRegister(i) ));

    gridRegs->SetCellValue(16, 0, uintToStr(pc));
    gridRegs->SetCellValue(17, 0, uintToStr(sp));
    gridRegs->Refresh();


    for (i=0; i<Cpu::RAM_SIZE; ++i)
        gridRam->SetCellValue(i%16, i/16, uintToStr( this->cpu.getRam(i) ));

    gridRam->Refresh();
    wxColour color = wxColour(160, 255, 255);

    for (i=0; i<Cpu::STACK_SIZE; ++i)
    {
        gridStack->SetCellBackgroundColour(i, 0, color);
        gridStack->SetCellValue(i, 0, uintToStr( this->cpu.getStack(i), true ));
    }

    gridStack->SetCellBackgroundColour(sp, 0, *wxLIGHT_GREY);
    gridStack->MakeCellVisible(sp, 0);
    gridStack->Refresh();

    checkCF->SetValue( this->cpu.getCF() );
    checkZF->SetValue( this->cpu.getZF() );
    checkIE->SetValue( this->cpu.getIE() );

    this->selectProgramPos(pc);

    for (i=0; i<Cpu::IO_PORTS_NO; ++i)
    {
        gridIn->SetCellValue(i, 0, uintToStr( this->cpu.ins[i].get() ));
        gridOut->SetCellValue(i, 0, uintToStr( this->cpu.outs[i].get() ));
    }

    gridIn->Refresh();
    gridOut->Refresh();
}

void MainWindow::updateProgramInfo()
{
    unsigned int i;
    uint32_t code;
    wxString s;

    DisAsm iasm;

    for (i=0; i<Cpu::INSTRUCTIONS_NO; ++i)
    {
        code = this->cpu.getInstructionCode(i);

        s = wxString::Format( wxT("%05X"), (unsigned int)code );
        gridProgram->SetCellValue(i, 0, s);

        iasm.setCode(code);
        s = wxString(iasm.toString(8).c_str(), wxConvUTF8);
        gridProgram->SetCellValue(i, 1, s);
    }
}

void MainWindow::selectProgramPos(int pos)
{
    wxColour color = wxColour(255, 255, 160);

    for (int i=0; i<(int)Cpu::INSTRUCTIONS_NO; ++i)
    {
        if (i == pos)
        {
            gridProgram->SetCellBackgroundColour(i, 0, *wxLIGHT_GREY);
            gridProgram->SetCellBackgroundColour(i, 1, *wxLIGHT_GREY);

            gridProgram->MakeCellVisible(i, 0);
        }
        else
        {
            gridProgram->SetCellBackgroundColour(i, 0, color);
            gridProgram->SetCellBackgroundColour(i, 1, color);
        }
    }

    gridProgram->Refresh();
}

void MainWindow::updateInInfo()
{
    wxString str;

    for (unsigned int i=0; i<Cpu::IO_PORTS_NO; ++i)
    {
        str = wxString(this->cpu.ins[i].getName().c_str(), wxConvUTF8);
        gridIn->SetCellValue(i, 1, str);
    }
}

void MainWindow::updateOutInfo()
{
    wxString str;

    for (unsigned int i=0; i<Cpu::IO_PORTS_NO; ++i)
    {
        str = wxString(this->cpu.outs[i].getName().c_str(), wxConvUTF8);
        gridOut->SetCellValue(i, 1, str);
    }
}

void MainWindow::showLoadProgramDialog()
{
    if (dlgLoadHex->ShowModal() == wxID_OK)
    {
        try
        {
            this->cpu.loadHex(dlgLoadHex->GetPath().mb_str());
            statusBar->SetStatusText(_("File: ") + dlgLoadHex->GetFilename(), 1);
        }
        catch (...)
        {
            wxMessageBox(_("Cannot load file \"") +
                         dlgLoadHex->GetFilename() + _("\""),
                         _("Error"), wxICON_ERROR, this);
        }

        this->updateProgramInfo();
    }
}

void MainWindow::addComponent(wxWindow* component)
{
    component->Show();
}

void MainWindow::updateGridRegsCell(int row)
{
    unsigned int val;

    try
    {
        val = this->strToUint(gridRegs->GetCellValue(row, 0));

        if ((row >= 0) && (row <= (int)Cpu::REGS_NO)) // s0 - sF
            this->cpu.setRegister(row, (uint8_t)val);

        else if (row == 16) // PC
            this->cpu.setPC(val);

        else if (row == 17) // SP
            this->cpu.setSP(val);
    }
    catch (...)
    {
        wxMessageBox(_("Incorrect value"),
                     _("Error"), wxICON_ERROR);
    }
}

void MainWindow::updateGridRamCell(int col, int row)
{
    unsigned int val;

    try
    {
        if ((col >= 0) && (col <= 3) && (row >= 0) && (row <= 15))
        {
            val = this->strToUint(gridRam->GetCellValue(row, col));
            this->cpu.setRam(col*16 + row, (uint8_t)val);
        }
    }
    catch (...)
    {
        wxMessageBox(_("Incorrect value"),
                     _("Error"), wxICON_ERROR);
    }
}

void MainWindow::updateGridStackCell(int row)
{
    unsigned int val;

    try
    {
        if ((row >= 0) && (row <= (int)Cpu::STACK_SIZE))
        {
            val = this->strToUint(gridStack->GetCellValue(row, 0));
            this->cpu.setStack(row, val);
        }
    }
    catch (...)
    {
        wxMessageBox(_("Incorrect value"),
                     _("Error"), wxICON_ERROR);
    }
}

void MainWindow::updateGridProgramCell(int row)
{
    unsigned int val;

    try
    {
        if ((row >= 0) && (row <= (int)Cpu::INSTRUCTIONS_NO))
        {
            val = this->strToUint(gridProgram->GetCellValue(row, 0));
            this->cpu.setInstructionCode(row, val);
        }
    }
    catch (...)
    {
        wxMessageBox(_("Incorrect value"),
                     _("Error"), wxICON_ERROR);
    }
}

void MainWindow::step()
{
    if (!this->cpuThread.IsRunning())
    {
        this->cpu.execute();
        this->updateCpuInfo();
    }
}

void MainWindow::showPane(wxWindow *window, bool show)
{
    wxAuiPaneInfo &pane = auiManager->GetPane(window);

    if (pane.IsOk())
    {
        if ((show) && (!pane.IsShown()))
        {
            pane.Show();
            auiManager->Update();
        }

        else if ((!show) && (pane.IsShown()))
        {
            pane.Hide();
            auiManager->Update();
        }
    }
}
