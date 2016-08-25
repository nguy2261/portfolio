#ifndef TestFlash_H
#define TestFlash_H

#include "libphoto.h"

class ColorData;
class PixelBuffer;
class Tool;

class TestFlash 
{   public:
        TestFlash();
        void createTestResultTool();
        void createTestResultFilter();
        void runTestTool();
        void runTestFilter();
        bool compareBuffer(PixelBuffer* test, PixelBuffer* comp);
    private:
        Tool **m_tools;
        PixelBuffer* m_testBuffer;
        PixelBuffer* m_expectBuffer;
};
#endif