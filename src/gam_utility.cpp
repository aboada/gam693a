
#include <stdio.h>
#include <limits.h>

#include "gam_utility.h"

void gam::Utility::initRandNumberGen() {
	int fp, bytesRead;
	unsigned int seed;

	if( !( fp = open(PATH_TO_URANDOM, O_RDONLY) ) )
	{
		fprintf(stderr, "ERROR: file %s could not be opened.\n"
			"This program will finish.\n", PATH_TO_URANDOM);
		exit(EXIT_FAILURE);
	}

	bytesRead = read(fp, &seed, sizeof(seed));
	close(fp);

	if( bytesRead < 0 )
	{
		fprintf(stderr, "ERROR: could not be read from: %s.\n"
			"The program will end.\n", PATH_TO_URANDOM);
		exit(EXIT_FAILURE);
	}

	srand(seed);
}

unsigned int gam::Utility::getRandom32() {
/* REMOVE THIS! 
limInf + (rand() * ( 1.0 /		\
												( RAND_MAX + 1.0 ) ) * 		\
												(limSup - limInf) ) */

  return (rand() * ( 1.0 / ( RAND_MAX + 1.0 ) ) * (UINT_MAX);
} // [0,UINT_MAX]

//unsigned int gam::Utility::getRandom32(unsigned int a, unsigned int b); // [a,b]
//unsigned int gam::Utility::getRandom32(unsigned int l); // [0,l]