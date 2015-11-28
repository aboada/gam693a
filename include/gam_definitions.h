#ifndef GAM_INCLUDE_DEFINITIONS_H_
#define GAM_INCLUDE_DEFINITIONS_H_

#include <math.h>
#include <float.h>

#define PATH_TO_URANDOM           "/dev/urandom"

#ifndef EXIT_FAILURE
#define EXIT_FAILURE              (1)
#endif

#define GAM_X_COMPONENT_BITS      16
#define GAM_Y_COMPONENT_BITS      16
#define GAM_BIT_ARRAY_SIZE        (GAM_X_COMPONENT_BITS + GAM_Y_COMPONENT_BITS)

#define GAM_INIT_X_VAL            (10)
#define GAM_INIT_Y_VAL            (10)
#define ROSENBROCK(x,y)           ( 100 * ((y-(x*x)*(y-(x*x)))+((1-x)*(1-x))) )
#define FITNESS_FUNCTION(x,y)     ROSENBROCK(x,y)
#define FITNESS_MAX_VALUE         DBL_MAX
#define BITS_TO_DOUBLE(n,bits)    ( (double) ( n / (pow(2,bits) - 1) ) )

#define MIN_POP_SIZE              (20)
#define MIN_GENERATIONS           (50)

typedef unsigned int uint32;
typedef double FitnessType;

#endif // GAM_INCLUDE_DEFINITIONS_H_
