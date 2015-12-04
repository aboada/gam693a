# Makefile for the tests folder.

include ../Makefile.inc

all: rosenbrock_ga cross_in_tray_ga eggholder_ga dropwave_ga

BIN = \
  rosenbrock_ga cross_in_tray_ga eggholder_ga dropwave_ga

CCFLAGS = -Wall -std=c++11 -fPIC -I$(INCLUDE)

%: %.cpp $(GAM_LIB) 
	$(CC) -o $@ $(CCFLAGS) $^
	@echo ' '
	
clean:
	rm -f *~ *.o $(BIN)
