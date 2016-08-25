## A Makefile for test flash 
.SILENT: $(EXECUTABLE)

UNAME = $(shell uname)
CC 		= g++
CFLAGS 	= -g -c -Wall -w
LDFLAGS = -g



ifeq ($(UNAME), Darwin) # Mac OSX 
	LINK_LIBS += -framework glut -framework opengl
	EXECUTABLE = TestFlash
else # LINUX
	LINK_LIBS +=  -lglut -lGL -lGLU
	EXECUTABLE = TestFlash
endif

GLUI = glui
PNG = png
JPEG = jpeg
LIBPHOTO = libphoto

GLUI_PATH = ../../glui
JPEG_PATH = ../../jpeg-9a
PNG_PATH = ../../libpng-1.6.16
LIBPHOTO_PATH = ../../libphoto

GLUI_LIB = $(GLUI_PATH)/lib/lib$(GLUI).a
PNG_LIB = $(PNG_PATH)/lib/lib$(PNG).a
JPEG_LIB = $(JPEG_PATH)/lib/lib$(JPEG).a
LIBPHOTO_LIB = $(LIBPHOTO_PATH)/lib/$(LIBPHOTO).a


INCLUDE += -I$(GLUI_PATH)/include 
INCLUDE += -I$(PNG_PATH)/include
INCLUDE += -I$(JPEG_PATH)/include
INCLUDE += -I$(LIBPHOTO_PATH)/include

OBJECT_DIR = object_files
SOURCE_DIR = src

LINK_LIBS +=  -L$(GLUI_PATH)/lib/ -l$(GLUI) 
LINK_LIBS +=  -L$(PNG_PATH)/lib/ -l$(PNG)
LINK_LIBS +=  -L$(JPEG_PATH)/lib/ -l$(JPEG)
LINK_LIBS +=  -L$(LIBPHOTO_PATH)/lib/ -lphoto 
LINK_LIBS +=  -lz

# Include nvidia drivers if necessary:
#NVIDIA_LIB =  /usr/lib/nvidia-304 #or whichever nvidia number shows up in that dir
ifneq ($(NVIDIA_LIB), )
	LINK_LIBS += -L$(NVIDIA_LIB)
endif

OBJECTS = $(addprefix $(OBJECT_DIR)/,  $(FILENAMES:.cpp=.o)) 
CPPFILES = $(wildcard $(SOURCE_DIR)/*.cpp)
FILENAMES =  $(notdir $(CPPFILES))







all: setup $(EXECUTABLE)

rebuild: clean build

# Create the object_files directory only if it does not exist. 
setup: | $(OBJECT_DIR)

$(OBJECT_DIR): 
	mkdir -p $(OBJECT_DIR); \
	mkdir -p test/current

$(EXECUTABLE): $(GLUI_LIB) $(PNG_LIB) $(JPEG_LIB) $(LIBPHOTO_LIB) $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) $(LINK_LIBS) -o $@ 

# Explicitly defined build targets because of dependancy on other header files
$(OBJECT_DIR)/TestTool.o: $(SOURCE_DIR)/TestTool.cpp $(SOURCE_DIR)/TestTool.h $(LIBPHOTO_PATH)/src/ColorData.h $(LIBPHOTO_PATH)/src/PixelBuffer.h
	$(CC) $(CFLAGS) $(INCLUDE)  -o $@ $<

$(OBJECT_DIR)/PixelBuffer.o: $(LIBPHOTO_PATH)/src/PixelBuffer.cpp $(LIBPHOTO_PATH)/src/PixelBuffer.h $(LIBPHOTO_PATH)/src/ColorData.h 
	$(CC) $(CFLAGS) $(INCLUDE)  -o $@ $<

$(OBJECT_DIR)/ToolFactory.o: $(LIBPHOTO_PATH)/src/ToolFactory.cpp $(LIBPHOTO_PATH)/src/ToolFactory.h \
	$(LIBPHOTO_PATH)/src/ColorData.h $(LIBPHOTO_PATH)/src/Tool.h  $(LIBPHOTO_PATH)/src/TPen.h $(LIBPHOTO_PATH)/src/TEraser.h  \
	$(LIBPHOTO_PATH)/src/TCalligraphyPen.h $(LIBPHOTO_PATH)/src/THighlighter.h $(LIBPHOTO_PATH)/src/TSprayCan.h 
	$(CC) $(CFLAGS) $(INCLUDE)  -o $@ $<

# Pattern build targets
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(SOURCE_DIR)/%.h
	#'Compiling arbitrary .cpp file with .h'
	$(CC) $(CFLAGS) $(INCLUDE)  -o $@ $<

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	#'Compiling arbitrary .cpp file without .h'
	$(CC) $(CFLAGS) $(INCLUDE)  -o $@ $<

clean:
	\rm -rf $(OBJECT_DIR) $(EXECUTABLE); \
	rm -rf test/current;  

cleanall: clean cleanglui cleanjpeg cleanpng cleanlibphoto

cleanlibphoto:
	$(MAKE)  -C ./$(LIBPHOTO_PATH)/ clean

cleanglui:	
	$(MAKE)  -C ./$(GLUI_PATH)/ clean

cleanjpeg:
	$(MAKE) -C ./$(JPEG_PATH) distclean
	cd $(JPEG_PATH); \
	rm -rf lib bin include share

cleanpng:
	$(MAKE) -C ./$(PNG_PATH) distclean
	cd $(PNG_PATH); \
	rm -rf lib bin include share

$(LIBPHOTO_LIB): 
	cd $(LIBPHOTO_PATH); \
	$(MAKE) -C $(LIBPHOTO_PATH) all

$(GLUI_LIB): 
	cd $(GLUI_PATH); \
	$(MAKE) -C $(GLUI_PATH) all

$(PNG_LIB):
	cd $(PNG_PATH); \
	./configure --enable-shared=no  --prefix=$(abspath $(PNG_PATH))
	$(MAKE) -C $(PNG_PATH)
	$(MAKE) -C $(PNG_PATH) check
	$(MAKE) -C $(PNG_PATH) install

$(JPEG_LIB): 
	cd $(JPEG_PATH); \
	./configure --enable-shared=no --prefix=$(abspath $(JPEG_PATH))
	$(MAKE) -C $(JPEG_PATH)
	$(MAKE) -C $(JPEG_PATH) check
	$(MAKE) -C $(JPEG_PATH) install
