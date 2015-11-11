#ifndef GAM_INCLUDE_UTILITY_H_
#define GAM_INCLUDE_UTILITY_H_

#define PATH_TO_URANDOM "/dev/urandom"
#define EXIT_FAILURE    (1)

namespace gam {

  class Utility {
    public:
      static void initRandNumberGen();
      static unsigned int getRandom32(); // [0,UINT_MAX]
      static unsigned int getRandom32(unsigned int a, unsigned int b); // [a,b]
      static unsigned int getRandom32(unsigned int l); // [0,l]
  }
  
}

#endif // GAM_INCLUDE_UTILITY_H_
