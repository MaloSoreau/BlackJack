

CC = g++
CDEBUG = -g
CFLAGS ?= -Wall
CPPFLAGS ?= -Iinclude

OPATH = obj
CPATH = src
BINPATH = bin

EXEC = main
OBJECTS = $(addprefix $(OPATH)/, main.o carte.o pioche.o simulation.o)

VERSION = $(shell git describe --tag --abbrev=0)

vpath %.o obj
vpath %.c src
vpath %.h include
vpath main bin

all: main
$(EXEC): $(OBJECTS)
	mkdir -p $(BINPATH)
	$(CC) -o $(BINPATH)/$@ $^ $(CFLAGS) $(CPPFLAGS)

$(OPATH)/%.o: $(CPATH)/%.cpp
	mkdir -p $(OPATH)
	$(CC) $(CDEBUG) -o $@ $(CPPFLAGS) -c $< $(CFLAGS)


.PHONY: clean dist doc

clean: 
	rm -rf $(OPATH)
	rm -rf $(BINPATH)
	rm -f *.tar.gz

dist:
	tar -cvJ src/ include/ -f "SoreauMalo-Blackjack.tar.gz"

doc:
	doxygen
	