#ifndef GAM_INCLUDE_GA_H_
#define GAM_INCLUDE_GA_H_

#include "gam_population.h"
#include "gam_individual.h"
#include "gam_parameters.h"


namespace gam {

  class GeneticAlgorithm {
    private:
      Parameters param;
      
    public:
      GeneticAlgorithm();
      GeneticAlgorithm(bool isInitByFile);
      GeneticAlgorithm(Parameters p);
      void initialize(bool isInitByFile);
      FitnessType evolve();
      void setParameters(Parameters p);
      Parameters getParameters();

    private:
      Population selection(Population p);
      Population offspring(Population p);
      Individual recombination(Individual i1, Individual i2);
      Individual mutate(Individual i);
      void evalPopulation(Population p);
      Population replacement(Population pCnt, Population pTmp);
  };
  
}

#endif // GAM_INCLUDE_GA_H_
