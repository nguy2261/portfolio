//
//  TPen.h
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  This tool simulates the usage of a Pen.
//  It has a MConstant mask with a radius of 1.0 (diameter of 3) and an opacity of 1.0
//
//  For educational purposes only.  Please do not post online.

#ifndef TPEN_H
#define TPEN_H

#include "Tool.h"

/** Class for the pen tool. */

class TPen : public Tool 
{
public:
	TPen();

	std::string getName() ;
};

#endif
