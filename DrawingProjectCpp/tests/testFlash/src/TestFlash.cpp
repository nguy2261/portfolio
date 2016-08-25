#include "ImageHandler.h"
#include "libphoto.h"
#include <cmath>
#include <math.h>
#include <string>
#include "TestFlash.h"
#include "ToolFactoryFlash.h"
#include <sstream>
using std::cout;
using std::endl;



template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

TestFlash::TestFlash(){
    cout << endl << "Start testing FlashPhoto " << endl;
}

void TestFlash::createTestResultTool(){
    cout << "Create Test Result " << endl;
    Tool **m_tools = new Tool* [ToolFactory::getNumTools()];
    for (int i = 0; i < ToolFactory::getNumTools(); i++) {
        m_tools[i] = ToolFactory::createTool(i);
    }

    for (int i = 0; i < 7; i++){
        if (i == 5){
            TStamp::setStampBuffer(ImageHandler::loadImage("test/colorCircles.png"));
        }
        
        if (i == 6){
            m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
        } else {
            m_testBuffer = new PixelBuffer(800,800,ColorData(1,1,0.95));
        }
        
        for (int x = 390; x < 410; x++){
            for (int y = 390; y < 410; y++){
                 m_tools[i]->applyToBuffer(x,800-y,ColorData(220,240,120),m_testBuffer);
            }
        }
        std::string save = "test/testtool" + to_string(i) + ".jpg";
        ImageHandler::saveImage(save,m_testBuffer);
    }
    
}

void TestFlash::createTestResultFilter(){
    cout << "Start Creating each Result Filter " << endl;
    
    //Blur Filter
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    Filter * f = FilterFactory::getFilter(FilterFactory::FILTER_BLUR, 1, 5.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_blurfilter.jpg",m_testBuffer);
    delete f;
    //Motion Blur Filter
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter( FilterFactory::FILTER_MOTION_BLUR, 2, 5.0, 1);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_motionblurfilter.jpg",m_testBuffer);
    delete f;
    //Edge Detection Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter( FilterFactory::FILTER_EDGE_DETECT, 0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_edgedetection.jpg",m_testBuffer);
    delete f;
    //Quantize Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_QUANTIZE, 1, 5);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_quantizefilter.jpg",m_testBuffer);
    delete f;
    //Saturate Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_SATURATION, 1, 5.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_saturatefilter.jpg",m_testBuffer);
    delete f;
    //Sharpen Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_SHARPEN, 1, 5.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_sharpenfilter.jpg",m_testBuffer);
    delete f;
    //Multi RGB Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_CHANNELS, 3, 2.0, 1.0, 1.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_multrgbfilter.jpg",m_testBuffer);
    delete f;
    //Threshold Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_THRESHOLD, 1, 0.5);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/test_thresholdfilter.jpg",m_testBuffer);
    delete f;
}

void TestFlash::runTestTool()
{   
    cout << endl << "Start Testing each tool " << endl;
    Tool **m_tools = new Tool* [ToolFactory::getNumTools()];
    for (int i = 0; i < ToolFactory::getNumTools(); i++) {
        m_tools[i] = ToolFactory::createTool(i);
    }
    for (int i = 0; i < 7; i++){
        if (i == 5){
            TStamp::setStampBuffer(ImageHandler::loadImage("test/colorCircles.png"));
        }
        
        if (i == 6){
            m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
        } else {
            m_testBuffer = new PixelBuffer(800,800,ColorData(1,1,0.95));
        }
        
        for (int x = 390; x < 410; x++){
            for (int y = 390; y < 410; y++){
                 m_tools[i]->applyToBuffer(x,800-y,ColorData(220,240,120),m_testBuffer);
            }
        }
        std::string save = "test/current/tool" + to_string(i) + ".jpg";
        ImageHandler::saveImage(save,m_testBuffer);
        m_testBuffer = ImageHandler::loadImage(save);
        std::string load = "test/testtool" + to_string(i) + ".jpg";

        m_expectBuffer = ImageHandler::loadImage(load);
        if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Tool " << m_tools[i]->getName() << " PASSED.\n"; 
        } else {
            cout << "Testing Tool " << m_tools[i]->getName() << " FAILED.\n";
         break;
        }
    }
}

void TestFlash::runTestFilter(){
    cout << endl << "Start Testing each Filter " << endl;
    
    //Blur Filter
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_blurfilter.jpg");
    Filter * f = FilterFactory::getFilter(FilterFactory::FILTER_BLUR, 1, 5.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/blurfilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/blurfilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Blur Filter PASSED.\n"; 
    } else {
           cout << "Testing Blur Filter FAILED.\n";
    }
    delete f;
    
    //Motion Blur Filter
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_motionblurfilter.jpg");
    f = FilterFactory::getFilter( FilterFactory::FILTER_MOTION_BLUR, 2, 5.0, 1);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/motionblurfilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/motionblurfilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Motion Blur Filter PASSED.\n"; 
    } else {
           cout << "Testing Motion Blur Filter FAILED.\n";
    }
    delete f;
    
    //Edge Detection Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_edgedetection.jpg");
    f = FilterFactory::getFilter( FilterFactory::FILTER_EDGE_DETECT, 0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/edgefilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/edgefilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Edge Detection Filter PASSED.\n"; 
    } else {
           cout << "Testing Edge Detection Filter FAILED.\n";
    }
    delete f;
    
    //Quantize Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_quantizefilter.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_QUANTIZE, 1, 5);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/quantizefilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/quantizefilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Quantize Filter PASSED.\n"; 
    } else {
           cout << "Testing Quantize Filter FAILED.\n";
    }
    delete f;
    
    //Saturate Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_saturatefilter.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_SATURATION, 1, 5.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/saturatefilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/saturatefilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Saturate Filter PASSED.\n"; 
    } else {
           cout << "Testing Saturate Filter FAILED.\n";
    }
    delete f;
    
    //Sharpen Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_sharpenfilter.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_SHARPEN, 1, 5.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/sharpenfilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/sharpenfilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Sharpen Filter PASSED.\n"; 
    } else {
           cout << "Testing Sharpen Filter FAILED.\n";
    }
    delete f;
    
    
    //Multi RGB Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_multrgbfilter.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_CHANNELS, 3, 2.0, 1.0, 1.0);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/mulrgbfilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/mulrgbfilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Multi RGB Filter PASSED.\n"; 
    } else {
           cout << "Testing Multi RGB Filter FAILED.\n";
    }
    delete f;
    
    //Threshold Filter 
    m_testBuffer = ImageHandler::loadImage("test/snaily.jpg");
    m_expectBuffer = ImageHandler::loadImage("test/test_thresholdfilter.jpg");
    f = FilterFactory::getFilter(FilterFactory::FILTER_THRESHOLD, 1, 0.5);
    FilterFactory::applyFilter(f, m_testBuffer);
    ImageHandler::saveImage("test/current/thresholdfilter.jpg",m_testBuffer);
    m_testBuffer = ImageHandler::loadImage("test/current/thresholdfilter.jpg");
    if(compareBuffer(m_testBuffer,m_expectBuffer)){
           cout << "Testing Threshold Filter PASSED.\n"; 
    } else {
           cout << "Testing Threshold Filter FAILED.\n";
    }
    delete f;
    
}

bool TestFlash::compareBuffer(PixelBuffer* test, PixelBuffer* comp){
    bool result = true;
    if (test->getWidth() == comp->getWidth() && test->getHeight() == comp->getHeight())
            {
                for(int iterX = 0; iterX < test->getWidth();iterX++){
                    for(int iterY = 0; iterY < test->getHeight();iterY++){
                        ColorData a = test->getPixel(iterX,iterY);
                        ColorData b = comp->getPixel(iterX,iterY);
                        
                        float aRed = roundf(a.getRed() * 100) / 100;
                        float aGreen = roundf(a.getGreen() * 100) / 100;
                        float aBlue = roundf(a.getBlue() * 100) / 100;
                        
                        float bRed = roundf(b.getRed() * 100) / 100;
                        float bGreen = roundf(b.getGreen() * 100) / 100;
                        float bBlue = roundf(b.getBlue() * 100) / 100;
        
                        if (aRed != bRed || aGreen != bGreen || aBlue != bBlue)
                        {

                            result = false;
                            break;
                            break;
                        }
                    }
                }
            }
     else
         result = false;
     return result;
}