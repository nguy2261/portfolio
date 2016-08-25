//
//  ToolFactory.h
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  For educational purposes only.  Please do not post online.

#ifndef TOOLFACTORYMIA_H
#define TOOLFACTORYMIA_H

#include <vector>

class Tool;

/** This is the factory class for tools specific to Mia*/

class ToolFactory 
{
public:
	enum TOOLS 
	{
		TOOL_PEN = 0,
        TOOL_STAMP,
		NUMTOOLS
	};
	
	static int getNumTools();
	static Tool* createTool(int toolID);
};

#endif
