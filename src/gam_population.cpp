#include <iostream>
#include <algorithm>

#include "gam_population.h"
#include "gam_utility.h"

using namespace std;
using namespace gam;

Population::Population() {
  popsize=0;
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
  delete popSize;
  delete members;
  }

void Population::initPopulation() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members.push_back( new Individual( Utility.getRandom32() ) );
  }
}

void Population::evalFitness() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members[i].computeFitness();
  }
}

void sortByFitness(const Individual& i1, const Individual& i2) {
  return i1.getFitness() < i2.getFitness();
}

void Population::sort() {
  sort(members.begin(), members.end(), sortByFitness);
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

