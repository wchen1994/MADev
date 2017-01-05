CXXFLAGS=-Wall -g -Isrc
CC=g++

LDLIBS+=$(LIBS_SFML)
LIBS_SFML=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

PROGRAM_DIR=./bin
SOURCES_DIR=./src
LIBRARY_DIR=./lib

PROGRAM_FILE=$(notdir $(patsubst %.cc,%,$(wildcard bin/*.cc)))
PROGRAM_PATH=$(addprefix $(PROGRAM_DIR)/, $(PROGRAM_FILE))

SOURCES_FILE=$(notdir $(wildcard src/*.cc))
SOURCES_PATH=$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILE))
TARGET_PATH=$(addprefix $(SOURCES_DIR)/, $(patsubst %.cc,%.o,$(SOURCES_FILE)))

LIBRARY_FILE=$(notdir $(wildcard lib/*.cc))
LIBRARY_PATH=$(addprefix $(LIBRARY_DIR)/, $(LIBRARY_FILE))
TARGET_SO_PATH=$(addprefix $(LIBRARY_DIR)/, $(patsubst %.cc,%.so,$(LIBRARY_FILE)))

all: $(TARGET_PATH) $(TARGET_SO_PATH) $(PROGRAM_PATH) 

$(PROGRAM_PATH): CXXFLAGS+=$(TARGET_PATH)

$(TARGET_PATH): $(SOURCES_PATH)
	$(CC) $(CXXFLAGS) -c $(patsubst %.o,%.cc,$@) -o $@ $(LDLIBS)

$(TARGET_SO_PATH): $(LIBRARY_PATH)
	$(CC) $(CXXFLAGS) -fPIC -shared $(patsubst %.so,%.cc,$@) -o $@ $(LDLIBS)

.PHONY:clean
clean:
	rm -rf $(PROGRAM_PATH)
	rm -rf $(TARGET_PATH)
