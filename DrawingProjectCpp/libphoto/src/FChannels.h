//
//  FChannels.h
//  PhotoShop Proj
//
//  Created by Seth Johnson on 4/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  For educational purposes only.  Please do not post online.

#ifndef FCHANNELS_H
#define FCHANNELS_H

#include <stdio.h>
#include "Filter.h"

/** A filter that allows you to set the values for an image's RGB (red, green, blue) channels. */
class FChannels : public Filter {
    virtual ColorData generatePixel(const PixelBuffer & buffer, int x, int y) const;
    
    float m_red;
    float m_green;
    float m_blue;
public:
    FChannels(float r, float g, float b) : m_red(r), m_green(g), m_blue(b)
    {
        
    }
    
};

#endif
