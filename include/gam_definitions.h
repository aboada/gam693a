#ifndef GAM_INCLUDE_DEFINITIONS_H_
#define GAM_INCLUDE_DEFINITIONS_H_

#include <math.h>
#include <float.h>

#define PATH_TO_URANDOM           "/dev/urandom"

#ifndef EXIT_FAILURE
#define EXIT_FAILURE              (1)
#endif

#define GAM_X_COMPONENT_BITS      32
#define GAM_Y_COMPONENT_BITS      32
#define GAM_BIT_ARRAY_SIZE        (GAM_X_COMPONENT_BITS + GAM_Y_COMPONENT_BITS)

#define GAM_INIT_X_VAL            (10)
#define GAM_INIT_Y_VAL            (10)

#define FITNESS_MAX_VALUE         DBL_MAX

#define BITS_TO_DOUBLE(n,bits, min, max)    ( (double) ( ( (max - min) * n ) / \
                                              ( pow(2,bits) -1 ) ) + min )

#define MIN_POP_SIZE              (20)
#define MIN_GENERATIONS           (50)

typedef unsigned long long int uint32;
typedef double FitnessType;

#endif // GAM_INCLUDE_DEFINITIONS_H_
