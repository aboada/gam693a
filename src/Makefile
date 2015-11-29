# Makefile for the src folder.

include ../Makefile.inc

all: gam archive

GAM =                 \
	gam_ga.o            \
	gam_individual.o    \
	gam_parameters.o    \
	gam_population.o    \
	gam_utility.o
	
gam: $(GAM)

#   Compiling statements.
#   __________________________________________________________________

%.o: %.cpp
	$(CC) $(CCFLAGS) $<

#   Archiving statements.
#   __________________________________________________________________

archive: $(GAM) 
	@(mkdir -p $(LIB))
	$(ARCH) $(ARCHFLAGS) $(GAM_LIB) $(GAM)
	$(RANLIB) $(GAM_LIB)
	@echo ' '
	@echo '----- Library created! Check for ' $(GAM_LIB)
	@echo ' '

#   Utilities.
#   __________________________________________________________________

clean:
	rm -f *~ *.o
