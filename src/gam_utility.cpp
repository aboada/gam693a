#include "gam_utility.h"

using namespace gam;

void Utility::initRandNumberGen() {
	int fp, bytesRead;
	unsigned int seed;

	if( !( fp = open(PATH_TO_URANDOM, O_RDONLY) ) )
	{
		fprintf(stderr, "ERROR: file %s could not be opened.\n"
			"This program will be aborted.\n", PATH_TO_URANDOM);
		exit(EXIT_FAILURE);
	}

	bytesRead = read(fp, &seed, sizeof(seed));
	close(fp);

	if( bytesRead < 0 )
	{
		fprintf(stderr, "ERROR: could not read from: %s.\n"
			"The program will be aborted.\n", PATH_TO_URANDOM);
		exit(EXIT_FAILURE);
	}

	srand(seed);
}

double Utility::getRandomF64() {
  return ( rand() * ( 1.0 / ( RAND_MAX + 1.0 ) ) * (1.0) );
}

unsigned int Utility::getRandomUI32() {  // [0,UINT_MAX]
  return ( rand() * ( 1.0 / ( RAND_MAX + 1.0 ) ) * (UINT_MAX) );
}

unsigned int Utility::getRandomUI32(unsigned int a, unsigned int b) {  
  // [a,b]
  return  a + (rand() * ( 1.0 /	( RAND_MAX + 1.0 ) ) * (b - a) );
}

