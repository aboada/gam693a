## Main makefile.

include Makefile.inc

all: gamlib test

gamlib:
	@( cd $(SRC); $(MAKE) )
	
clean: cleanroot cleanlib

cleanroot:
	@(rm -f *~)

cleanlib:
	@( cd $(SRC); $(MAKE) clean )
	@( cd $(LIB); $(MAKE) clean )
	
