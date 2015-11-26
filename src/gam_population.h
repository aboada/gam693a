#ifndef GAM_INCLUDE_POPULATION_H_
#define GAM_INCLUDE_POPULATION_H_
#include <vector>
#include "gam_individual.h"

namespace gam {

  class Population {
    private:
      unsigned int popSize;
      std::vector<Individual> members;
      
    public:
      Population();
      Population(unsigned int size);
      ~Population();
      void initPopulation();
      void evalFitness();
      void sort();
      Individual getIndividual(unsigned int pos);
      void setIndividual(unsigned int pos, Individual ind);
      unsigned int getPopulationSize();
    private:
      void sortByFitness(const Individual& i1, const Individual& i2);
  };
  
}

#endif // GAM_INCLUDE_POPULATION_H_
