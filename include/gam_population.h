#ifndef GAM_INCLUDE_POPULATION_H_
#define GAM_INCLUDE_POPULATION_H_

#include <iostream>
#include <vector>
#include <algorithm>

#include "gam_individual.h"
#include "gam_parameters.h"

namespace gam {
  
  class Population {
    private:
      unsigned int popSize;
      std::vector<Individual> members;
      static bool sortByFitness(const Individual& i1, const Individual& i2);
      
    public:
      Population();
      Population(unsigned int size);
      ~Population();
      void initialize();
      void initialize(unsigned int size);
      void evaluate(const Parameters &p);
      void sort();
      Individual getIndividual(unsigned int pos);
      void setIndividual(unsigned int pos, Individual ind);
      unsigned int getPopulationSize();
      void addIndividual(Individual ind);
      void print(const Parameters &p);
      void rescale();
  };
  
}

#endif // GAM_INCLUDE_POPULATION_H_
