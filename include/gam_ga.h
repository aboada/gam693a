#ifndef GAM_INCLUDE_GA_H_
#define GAM_INCLUDE_GA_H_

#include "gam_population.h"
#include "gam_individual.h"

namespace gam {

  class GeneticAlgorithm {
    private:
      Parameters param;
      
    public:
      GeneticAlgorithm();
      GeneticAlgorithm(boolean isInitByFile);
      void initialize(boolean isInitByFile);
      fitness_t evolve();

    private:
      Population selection(Population p);
      Population recombination(Population p);
      void evalPopulation(Population p);
      Population replacement(Population pCnt, Population pTmp);
  };
  
}

#endif // GAM_INCLUDE_GA_H_
