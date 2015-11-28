#ifndef GAM_INCLUDE_PARAMETERS_H_
#define GAM_INCLUDE_PARAMETERS_H_

#include "gam_definitions.h"

#define DEFAULT_POP_SIZE          (100)
#define DEFAULT_MAX_GEN           (300)
#define DEFAULT_GENERATIONAL_GAP  (0.1)
#define DEFAULT_MUTATION_PROB     (0.05)
#define DEFAULT_BIT_MUTATION_PROB (0.1)

namespace gam {
  
  class Parameters {
    private:
      unsigned int popSize;
      unsigned int maxGenerations;
      double generationalGap;
      double mutationProb;
      double bitMutationProb;
    
    public:
      Parameters();
      Parameters(bool isInitByFile);
      void initByDefault();
      void initByFile();
      unsigned int getPopulationSize();
      unsigned int getMaxGenerations();
      double getGenerationalGap();
      unsigned int getNPreservedIndividuals();
      unsigned int getNReplacedIndividuals();
      double getMutationProb();
      double getBitMutationProb();
      void setPopulationSize(unsigned int size);
      void setMaxGenerations(unsigned int max);
      void setGenerationalGap(double gap);
      void setMutationProb(double prob);
      void setBitMutationProb(double prob);
  };
  
}

#endif // GAM_INCLUDE_PARAMETERS_H_
