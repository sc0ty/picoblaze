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

	Cpu thread controlling class
*/

#include "CpuThread.h"

CpuThread::CpuThread() : wxThread(wxTHREAD_DETACHED), running(false), cpu(NULL)
{
    this->Create();
}

CpuThread::~CpuThread()
{
}

void CpuThread::setCpu(Cpu *cpu)
{
    this->cpu = cpu;
}

int CpuThread::getCounter()
{
    this->counterMutex.Lock();
    int c = this->counter;
    this->counter = 0;
    this->counterMutex.Unlock();

    return c;
}

wxThread::ExitCode CpuThread::Entry()
{
    int i;

    if (cpu != NULL)
    {
        while (!TestDestroy())
        {
            for (i=0; i<1024; ++i)
            {
                this->cpu->execute();
            }

            this->counterMutex.Lock();
            this->counter += 1024;
            this->counterMutex.Unlock();
        }
    }

    return static_cast<ExitCode>(NULL);
}
