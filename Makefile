CXXFLAGS=-Wall -g -Isrc

#CXX=g++

CXX=i686-w64-mingw32-g++
CXXFLAGS+= -static-libgcc -static-libstdc++ -I/opt/SFML-2.4.1/include -L/opt/SFML-2.4.1/lib

LIBS_SFML=-lsfml-graphics -lsfml-window -lsfml-system
LDLIBS+=$(LIBS_SFML)

SOURCES=$(wildcard src/*.hpp)
TARGET=$(patsubst %.hpp,%.o,$(SOURCES))
PROGRAM=build/game

all: $(PROGRAM)

$(PROGRAM):$(TARGET)
	$(CXX) $(CXXFLAGS) $(notdir $@)/$(patsubst %,%.cc,$(notdir $@)) $(TARGET) $(LDLIBS) -o $@

#PROGRAM_DIR=./bin
#SOURCES_DIR=./src
#LIBRARY_DIR=./lib
#
#PROGRAM_FILE=$(notdir $(patsubst %.cc,%,$(wildcard bin/*.cc)))
#PROGRAM_PATH=$(addprefix $(PROGRAM_DIR)/, $(PROGRAM_FILE))
#
#SOURCES_FILE=$(notdir $(wildcard src/*.cc))
#SOURCES_PATH=$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILE))
#TARGET_PATH=$(addprefix $(SOURCES_DIR)/, $(patsubst %.cc,%.o,$(SOURCES_FILE)))
#
#LIBRARY_FILE=$(notdir $(wildcard lib/*.cc))
#LIBRARY_PATH=$(addprefix $(LIBRARY_DIR)/, $(LIBRARY_FILE))
#TARGET_SO_PATH=$(addprefix $(LIBRARY_DIR)/, $(patsubst %.cc,%.so,$(LIBRARY_FILE)))
#
#all: $(PROGRAM_PATH) 
#
#$(PROGRAM_PATH): $(TARGET_PATH)
#$(PROGRAM_PATH):
#	$(CC) $(CXXFLAGS) $(patsubst %,%.cc,$@) $(TARGET_PATH) -o $@ $(LDLIBS)
#
#$(TARGET_PATH): $(SOURCES_PATH)
#	$(CC) $(CXXFLAGS) -c $(patsubst %.o,%.cc,$@) -o $@ $(LDLIBS)
#
#$(TARGET_SO_PATH): $(LIBRARY_PATH)
#	$(CC) $(CXXFLAGS) -fPIC -shared $(patsubst %.so,%.cc,$@) -o lib/libResources.so $(LDLIBS)

.PHONY:clean
clean:
	rm -rf $(TARGET)
	rm -rf $(PROGRAM)
