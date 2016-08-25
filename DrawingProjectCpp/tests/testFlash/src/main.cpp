#include "libphoto.h"
#include "TestFlash.h"

int main(int argc, char* argv[])
{
	TestFlash* test = new TestFlash();
	//test->createTestResultTool();
    test->runTestTool();
    //test->createTestResultFilter();
    test->runTestFilter();
    return 0;
}
