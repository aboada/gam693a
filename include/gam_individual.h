#ifndef GAM_INCLUDE_INDIVIDUAL_H_
#define GAM_INCLUDE_INDIVIDUAL_H_

#include "gam_chromosome.h"

typedef unsigned int uint32;
typedef double FitnessType;

namespace gam{
  class Individual{
    private:
      fitness_t fitness;
      chromosome chrome;
      
    public:
      Individual(uint32 b);	
      Individual();
      void compFitness();
      fitness_t getFitness();
      void setChromosome(chromosome ch);
      void setChromosome(uint32 b);
      chromosome getChromosome();
	};
};


#endif
