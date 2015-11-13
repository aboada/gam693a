#include <iostream>
#include "gam_population.h"
#include "gam_utility.h"

using namespace std;

gam::Population::Population(unsigned int size){
  if ( size > 0 ) {
    popSize = size;
    members.reserve(size);
  }
  else {
    cerr << "ERROR: Failure to construct object of 'Population'" << endl;
    cerr << "Reason: population size < 1 (" << size << ")" << endl;
  }
}

gam::Population::initPopulation() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members.push_back( new Individual( gam::Utility.getRandom32() ) );
  }
}

gam::Population::evalFitness() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members[i].computeFitness();
  }
}

