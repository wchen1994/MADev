UNAME := $(shell uname)

CXXFLAGS=-Wall -g -Isrc

SOURCES=$(wildcard src/*.hpp)
PROGRAM_NAME=game

ifeq ($(UNAME), Linux)
CXX=g++
BUILD_PATH=build/Unix
else
CXX=i686-w64-mingw32-g++
CXXFLAGS+= -static-libgcc -static-libstdc++ -I/opt/SFML-2.4.1/include -L/opt/SFML-2.4.1/lib
BUILD_PATH=build/Window
endif 
LIBS_SFML=-lsfml-graphics -lsfml-window -lsfml-system
LDLIBS+=$(LIBS_SFML)

PROGRAM=$(addprefix $(BUILD_PATH)/bin/, $(PROGRAM_NAME))
TARGET=$(addprefix $(BUILD_PATH)/, $(patsubst %.hpp,%.o,$(SOURCES)))

all: $(PROGRAM)

$(PROGRAM):$(TARGET)
	$(CXX) $(CXXFLAGS) $(notdir $@)/$(patsubst %,%.cc,$(notdir $@)) $(TARGET) $(LDLIBS) -o $@
	
$(TARGET):$(SOURCE)
	$(CXX) $(CXXFLAGS) -c src/$(patsubst %.o,%.cc,$(notdir $@)) -o $(BUILD_PATH)/src/$(notdir $@)

os:
	echo $(UNAME)

.PHONY:clean
clean:
	rm -rf src/*.gch
	rm -rf src/*.o
	rm -rf $(PROGRAM).exe
	rm -rf $(TARGET)
	rm -rf $(PROGRAM)
