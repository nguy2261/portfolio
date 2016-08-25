## A Makefile for libphoto

UNAME = $(shell uname)
CC 		= g++
CFLAGS 	= -g -c -Wall -lstdc++
LDFLAGS = -g
LIB_DIR = lib


ifeq ($(UNAME), Darwin) # Mac OSX 
	LINK_LIBS += -framework glut -framework opengl
	EXECUTABLE = libPho
else # LINUX
	LINK_LIBS +=  -lglut -lGL -lGLU
	EXECUTABLE = libPho
endif

GLUI = glui
PNG = png
JPEG = jpeg

GLUI_PATH = ../glui
JPEG_PATH = ../jpeg-9a
PNG_PATH = ../libpng-1.6.16

GLUI_LIB = $(GLUI_PATH)/lib/lib$(GLUI).a
PNG_LIB = $(PNG_PATH)/lib/lib$(PNG).a
JPEG_LIB = $(JPEG_PATH)/lib/lib$(JPEG).a


INCLUDE += -I$(GLUI_PATH)/include 
INCLUDE += -I$(PNG_PATH)/include
INCLUDE += -I$(JPEG_PATH)/include


OBJECT_DIR = object_files
SOURCE_DIR = src

LINK_LIBS +=  -L$(GLUI_PATH)/lib/ -l$(GLUI) 
LINK_LIBS +=  -L$(PNG_PATH)/lib/ -l$(PNG)
LINK_LIBS +=  -L$(JPEG_PATH)/lib/ -l$(JPEG) 
LINK_LIBS +=  -lz

# Include nvidia drivers if necessary:
#NVIDIA_LIB =  /usr/lib/nvidia-304 #or whichever nvidia number shows up in that dir
ifneq ($(NVIDIA_LIB), )
	LINK_LIBS += -L$(NVIDIA_LIB)
endif

OBJECTS = $(addprefix $(OBJECT_DIR)/,  $(FILENAMES:.cpp=.o)) 
CPPFILES = $(wildcard $(SOURCE_DIR)/*.cpp)
FILENAMES =  $(notdir $(CPPFILES))

all: setup DEPS setuplibrary BUILD_LIB

rebuild: clean all

# Create the object_files directory only if it does not exist. 
setup: | $(OBJECT_DIR)
setuplibrary: | $(LIB_DIR)

$(OBJECT_DIR): 
	mkdir -p $(OBJECT_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

BUILD_LIB: $(OBJECTS)
	ar -r $(LIB_DIR)/libphoto.a  $(OBJECTS)

DEPS: $(GLUI_LIB) $(PNG_LIB) $(JPEG_LIB) $(OBJECTS)

# Pattern build targets
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp $(SOURCE_DIR)/%.h
	#'Compiling arbitrary .cpp file with .h'
	$(CC) $(CFLAGS)  $(INCLUDE) -o $@ $<

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	#'Compiling arbitrary .cpp file without .h'
	$(CC) $(CFLAGS)  $(INCLUDE)  -o $@ $<

clean:
	\rm -rf $(OBJECT_DIR) $(LIB_DIR)

$(GLUI_LIB): 
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
