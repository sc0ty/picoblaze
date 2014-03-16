/* Header to create Pre-Compiled Header (PCH) */

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
//    #include "cpu/cpu.h"
#endif // WX_PRECOMP

#endif // WX_PCH_H_INCLUDED
