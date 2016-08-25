##A makefile for testing
.SILENT: test_flash test_blurfilter test_edgedetection test_quantizefilter test_saturatefilter test_sharpenfilter \
	test_ test_multrgbfilter test_thresholdfilter test_poorinput

MIA_DIR = ../Mia

all: setup echo_blurfilter test_blurfilter \
	echo_edgedetection test_edgedetection \
	echo_quantizefilter test_quantizefilter \
	echo_saturatefilter test_saturatefilter \
	echo_sharphenfilter test_sharpenfilter \
	echo_multrgbfilter test_multrgbfilter \
	echo_thresholdfilter test_thresholdfilter \
	test_poorinput \
	echo_flashphoto test_flash

setup:
	mkdir ../Mia/testImages/testResults;

echo_blurfilter:
	@echo Testing command line blur filter...

test_blurfilter:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -blur 5.0 testImages/testResults/test_blurfilter.jpg; \
	./Mia testImages/testResults/test_blurfilter.jpg -compare testImages/expectedResults/expected_blurfilter.jpg

echo_edgedetection:	
	@echo Testing command line edge detection...
	
test_edgedetection:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -edgedetect testImages/testResults/test_edgedetection.jpg; \
	./Mia testImages/testResults/test_edgedetection.jpg -compare testImages/expectedResults/expected_edgedetection.jpg

echo_quantizefilter:
	@echo Testing command line quantize filter...
	
test_quantizefilter:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -quantize 5.0 testImages/testResults/test_quantizefilter.jpg; \
	./Mia testImages/testResults/test_quantizefilter.jpg -compare testImages/expectedResults/expected_quantizefilter.jpg

echo_saturatefilter:
	@echo Testing command line saturate filter...

test_saturatefilter:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -saturate 5.0 testImages/testResults/test_saturatefilter.jpg; \
	./Mia testImages/testResults/test_saturatefilter.jpg -compare testImages/expectedResults/expected_saturatefilter.jpg
	
echo_sharphenfilter:
	@echo Testing command line sharpen filter...

test_sharpenfilter:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -sharpen 5.0 testImages/testResults/test_sharpenfilter.jpg; \
	./Mia testImages/testResults/test_sharpenfilter.jpg -compare testImages/expectedResults/expected_sharpenfilter.jpg
	
echo_multrgbfilter:
	@echo Testing command line multrgb filter...

test_multrgbfilter:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -multrgb 2.0 1.0 1.0 testImages/testResults/test_multrgbfilter.jpg; \
	./Mia testImages/testResults/test_multrgbfilter.jpg -compare testImages/expectedResults/expected_multrgbfilter.jpg
	
echo_thresholdfilter:
	@echo Testing command line threshold filter...

test_thresholdfilter:
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jpg -thresh 0.5 testImages/testResults/test_thresholdfilter.jpg; \
	./Mia testImages/testResults/test_thresholdfilter.jpg -compare testImages/expectedResults/expected_thresholdfilter.jpg

test_poorinput:
	@echo
	@echo Testing poor user input...
	@echo Results should read as follows:
	@echo 	1 - Incorrect input filename : Resource temporarily unavailable
	@echo 	2 - Unsuccessfully saved image
	@echo 	3 - Command not found
	@echo
	cd $(MIA_DIR); \
	./Mia testImages/snaily.jp -thresh 0.5 testImages/test_thresholdfilter.jpg; \
	./Mia testImages/snaily.jpg -thresh 0.5 testImages/test_thresholdfilter.jp; \
	./Mia testImages/snaily.jpg -thres 0.5 testImages/test_thresholdfilter.jpg;
	@echo

echo_flashphoto:
	@echo Testing FlashPhoto...

test_flash:
	cd testFlash; \
	make -s; \
	./TestFlash

cleanall: clean clean_testflash

clean:
	rm -rf ../Mia/testImages/testResults

clean_testflash:
	cd testFlash; \
	make clean