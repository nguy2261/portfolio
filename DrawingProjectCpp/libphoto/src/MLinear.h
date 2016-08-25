//
//  MLinear.h
//  Student Support
//
//  Created by Seth Johnson on 2/9/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  MLinear is a Mask that is round, with a linear fall-off
//  from full intensity at the center to no intensity at the
//  extremity.
//
//  For educational purposes only.  Please do not post online.

#ifndef MLINEAR_H
#define MLINEAR_H

#include "Mask.h"

/** Mask shape for tools using linear mask. */

class MLinear : public Mask 
{
public:
	MLinear(float radius, float opacity);
protected:
	float getIntensity(int x, int y, float radius);
};

#endif
