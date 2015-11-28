#ifndef GAM_INCLUDE_UTILITY_H_
#define GAM_INCLUDE_UTILITY_H_

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
