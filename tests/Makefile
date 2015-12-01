# Makefile for the tests folder.

include ../Makefile.inc

all: default_ga

BIN = \
  default_ga

CCFLAGS = -Wall -std=c++11 -fPIC -I$(INCLUDE)

default_ga: default_ga.cpp $(GAM_LIB) 
	$(CC) -o $@ $(CCFLAGS) $^
	@echo ' '
	
clean:
	rm -f *~ *.o $(BIN)
