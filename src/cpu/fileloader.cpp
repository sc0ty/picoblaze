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

	Program loader from file
*/

#include <iostream>
#include <fstream>

#include "fileloader.h"

using namespace std;

int loadHexFile(const char *fileName, uint32_t *buf, unsigned int size)
{
    ifstream file;
    file.exceptions(ifstream::badbit);

    int read = 0;

    try
    {
        file.open(fileName);

        if (!file.is_open()) throw 0;

        while ((file.eof() == false) && ((unsigned)read < size))
        {
            file >> hex >> buf[read++];
        }

        file.close();
    }

    catch (...)
    {
        if (file.is_open())
            file.close();

        throw;
    }

    return read;
}
