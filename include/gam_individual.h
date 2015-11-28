#ifndef GAM_INCLUDE_INDIVIDUAL_H_
#define GAM_INCLUDE_INDIVIDUAL_H_

#include <algorithm> 

#include "gam_chromosome.h"
#include "gam_definitions.h"

namespace gam{

  class Individual{
    private:
      FitnessType fitness;
      Chromosome chrome;
      
    public:
      Individual(uint32 b);	
      Individual();
      Individual& operator = (const Individual &other); 
      void compFitness();
      FitnessType getFitness();
      void setChromosome(Chromosome ch);
      void setChromosome(uint32 b);
      Chromosome getChromosome();
      Individual& operator & (const Individual &parent); // crossover
      void mutate();
	};
	
};


#endif
