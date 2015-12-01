## Main makefile.

include Makefile.inc

all: gamlib test

gamlib:
	@( cd $(SRC); $(MAKE) )

test:
	@( cd $(TESTS); $(MAKE) )

clean: cleanroot cleanlib cleantest

cleanroot:
	@(rm -f *~)

cleanlib:
	@( cd $(SRC); $(MAKE) clean )
	@( cd $(LIB); $(MAKE) clean )

cleantest:
	@( cd $(TESTS); $(MAKE) clean )
