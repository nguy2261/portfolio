//
//  PixelBuffer.h
//
//  Created by CSCI3081W Guru
//  Copyright (c) 2015 CSCI3081W Guru. All rights reserved.
//
//  For educational purposes only.  Please do not post online.

#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

class ColorData;

/** Pixel buffer that will be applied to the canvas. */

class PixelBuffer 
{
public:
	// Constructors
	PixelBuffer(int w, int h, ColorData backgroundColor);
	~PixelBuffer();
	// Setters
	void setPixel(int x, int y, const ColorData& newPixel);
	
	// Getters
	ColorData getPixel(int x, int y) const;
	ColorData const * const getData() const;
	int getHeight() const;
	int getWidth() const;
    ColorData getBackground() const;
	// Member tasks
	void fillPixelBufferWithColor(ColorData initialPixels);
	
	// Static tasks
	static void copyPixelBuffer(const PixelBuffer * sourceBuffer, PixelBuffer * destinationBuffer);
    static PixelBuffer* duplicatePixelBuffer(const PixelBuffer * sourceBuffer);
private:
	// Array of pixel values
	ColorData * m_pixels;
	ColorData * m_backgroundColor;
	// Dimensions
	const int m_width;
	const int m_height;
};

#endif
