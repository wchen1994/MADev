UNAME := $(shell uname)

CXXFLAGS=-Wall -g -Isrc

ifeq ($(UNAME), Linux)
CXX=g++
else
CXX=i686-w64-mingw32-g++
CXXFLAGS+= -static-libgcc -static-libstdc++ -I/opt/SFML-2.4.1/include -L/opt/SFML-2.4.1/lib
endif

LIBS_SFML=-lsfml-graphics -lsfml-window -lsfml-system
LDLIBS+=$(LIBS_SFML)

SOURCES=$(wildcard src/*.hpp)
TARGET=$(patsubst %.hpp,%.o,$(SOURCES))
PROGRAM=build/game

all: $(PROGRAM)

$(PROGRAM):$(TARGET)
ifeq ($(UNAME), Linux)
	$(CXX) $(CXXFLAGS) $(notdir $@)/$(patsubst %,%.cc,$(notdir $@)) $(TARGET) $(LDLIBS) -o $@
else
	$(CXX) $(CXXFLAGS) $(notdir $@)/$(patsubst %,%.cc,$(notdir $@)) $(TARGET) $(LDLIBS) -o $@.exe
endif

os:
	echo $(UNAME)

.PHONY:clean
clean:
	rm -rf $(TARGET)
	rm -rf $(PROGRAM)
