//
//  FQuantize.h
//  PhotoShop Proj
//
//  Created by Seth Johnson on 4/3/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  For educational purposes only.  Please do not post online.

#ifndef FQUANTIZE_H
#define FQUANTIZE_H

#include "Filter.h"

/** Reduces the number of possible colors by binning each color value into the the 
number of bins specified. If using 4 bins, there will only be 4 possible intensity 
values for each color channel, spaced evenly: 0%, 33%, 66%, and 100%. */

class FQuantize : public Filter {
    virtual ColorData generatePixel(const PixelBuffer & buffer, int x, int y) const;
    
    int m_bins;
public:
    FQuantize(int bins) : m_bins(bins) {}
};

#endif 
