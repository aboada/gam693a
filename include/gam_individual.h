#ifndef GAM_INCLUDE_INDIVIDUAL_H_
#define GAM_INCLUDE_INDIVIDUAL_H_

#include <iostream>
#include <algorithm> 
#include <bitset>

#include "gam_chromosome.h"
#include "gam_definitions.h"
#include "gam_parameters.h"

namespace gam{

  class Individual{
    private:
      FitnessType fitness;
      Chromosome chrome;
      
    public:
      Individual(uint32 b);	
      Individual();
      Individual operator = (Individual other); 
      void computeFitness(const Parameters &p);
      FitnessType getFitness();
      void setFitness(FitnessType f);
      void setChromosome(Chromosome ch);
      void setChromosome(uint32 b);
      Chromosome getChromosome();
      Individual crossover(Individual parent);
      void mutate(double bitMutationProb);
      bool operator < ( const Individual& other );
      void print(bool computeFitness, const Parameters &p);
	};
	
};


#endif
