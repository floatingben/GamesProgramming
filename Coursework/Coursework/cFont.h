/*
==========================================================================
cFont.h
==========================================================================
*/

#ifndef _CFONT_H
#define _CFONT_H

// OpenGL Headers
#include "GameConstants.h"

using namespace std;

class cFont
{
private:

	//private variable that points in FTfont
	FTFont* theFont; 


public:

	//public variables 
	cFont();
	cFont(LPCSTR fontFileName, int fontSize);
	~cFont();
	FTFont* getFont();
	void printText(LPCSTR text, FTPoint textPos);

};
#endif