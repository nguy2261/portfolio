//
//  FEdge.h
//  PhotoShop Proj
//
//  Created by Seth Johnson on 4/3/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  For educational purposes only.  Please do not post online.

#ifndef FEDGE_H
#define FEDGE_H

#include "FilterConvolve.h"

class Kernel;

/** Creates a representation of the rate-of-change in the image. Pixels on the border of 
differently colored regions will be bright, while pixels in areas of low change will 
be dark. */
class FEdge : public FilterConvolve {
public:
    FEdge();
};

#endif
