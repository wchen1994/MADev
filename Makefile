CXXFLAGS=-Wall -g -Isrc
CC=g++

LDLIBS+=$(LIBS_SFML)
LIBS_SFML=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

PROGRAM_DIR=./bin
SOURCES_DIR=./src

PROGRAM_FILE=$(notdir $(patsubst %.cc,%,$(wildcard bin/*.cc)))
PROGRAM_PATH=$(addprefix $(PROGRAM_DIR)/, $(PROGRAM_FILE))

SOURCES_FILE=$(notdir $(wildcard src/*.cc))
SOURCES_PATH=$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILE))
TARGET_PATH=$(addprefix $(SOURCES_DIR)/, $(patsubst %.cc,%.o,$(SOURCES_FILE)))

#tmp:
#	echo $(SOURCES_PATH)

all:$(PROGRAM_PATH) $(TARGET_PATH)

$(TARGET_PATH): $(SOURCES_PATH)
	#echo $(SOURCES_PATH)
	$(CC) $(CXXFLAGS) -c $(patsubst %.o,%.cc,$@) -o $@ $(LDLIBS)

.PHONY:clean
clean:
	rm -rf $(PROGRAM_PATH)
	rm -rf $(TARGET_PATH)
