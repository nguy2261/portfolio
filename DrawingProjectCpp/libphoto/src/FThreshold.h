//
//  FThreshold.h
//  PhotoShop Proj
//
//  Created by Seth Johnson on 4/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  For educational purposes only.  Please do not post online.

#ifndef FTHRESHOLD_H
#define FTHRESHOLD_H

#include "Filter.h"

class PixelBuffer;
class ColorData;

/** Each of the color channels will be rounded up to the maximum value of 1.0 or 
down to the minimum value of 0.0 based on whether the pixel’s value is greater or 
less than the GLUI input value, respectively. */

class FThreshold : public Filter {
    virtual ColorData generatePixel(const PixelBuffer & buffer, int x, int y) const;
    
    float m_amount;
public:
    FThreshold(float amount) : m_amount(amount) {}
};


#endif
