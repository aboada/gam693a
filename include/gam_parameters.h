#ifndef GAM_INCLUDE_PARAMETERS_H_
#define GAM_INCLUDE_PARAMETERS_H_

namespace gam {
  
  class Parameters {
    private:
      static unsigned int popSize;
      static unsigned int maxGenerations;
      static double generationalGap;
      static double mutationProb;
      static double bitMutationProb;
    
    public:
      static void initByDefault();
      static void initByFile();
  };
  
}

#endif // GAM_INCLUDE_PARAMETERS_H_
