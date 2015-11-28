#include <iostream>
#include <algorithm>

#include "gam_population.h"
#include "gam_utility.h"

using namespace std;
using namespace gam;

Population::Population() {
  popSize = 0;
}

Population::Population(unsigned int size) {
  if ( size > 0 ) {
    popSize = size;
    members.reserve(size);
  }
  else {
    cerr << "ERROR: Failure to construct object of 'Population'" << endl;
    cerr << "Reason: population size < 1 (" << size << ")" << endl;
  }
}

Population::~Population() {
}

void Population::initPopulation() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members.push_back( Individual( Utility::getRandomUI32() ) );
  }
}

void Population::evalFitness() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members[i].computeFitness();
  }
}

bool sortByFitness(const Individual& i1, const Individual& i2) {
  Individual ind1 = i1;
  Individual ind2 = i2;
  
  return ind1 < ind2;
}

void Population::sort() {
  std::sort(members.begin(), members.end(), sortByFitness);
}

Individual Population::getIndividual(unsigned int pos) {
  return members[pos];
}

void Population::setIndividual(unsigned int pos, Individual ind) {
  members[pos] = ind;
}

unsigned int Population::getPopulationSize() {
  return popSize;
}

