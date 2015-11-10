#ifndef GAM_INCLUDE_POPULATION_H_
#define GAM_INCLUDE_POPULATION_H_

#include <vector>

namespace gam {
  class Population {
    private:
      unsigned int popSize;
      std::vector<Individual> members;
      
    public:
      Population(unsigned int size);
      ~Population();
      
      void initPopulation();
      void evalFitness();
  }
}

#endif // GAM_INCLUDE_POPULATION_H_
