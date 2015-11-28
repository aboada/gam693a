#ifndef GAM_INCLUDE_UTILITY_H_
#define GAM_INCLUDE_UTILITY_H_

#include <cstdio>
#include <climits>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#include "gam_definitions.h"

namespace gam {
  
  class Utility {
    public:
      static void initRandNumberGen();
      static double getRandomF64(); // double [0,1]
      static unsigned int getRandomUI32(); // [0,UINT_MAX]
      static unsigned int getRandomUI32(unsigned int a, unsigned int b); 
  };
  
}

#endif // GAM_INCLUDE_UTILITY_H_

