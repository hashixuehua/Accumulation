// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW   new( _CLIENT_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_NEW
#endif

#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// TODO: reference additional headers your program requires here
