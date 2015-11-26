#include <iostream>
#include <algorithm>

#include "gam_population.h"
#include "gam_utility.h"

using namespace std;

gam::Population::Population() {
  popsize=0;
}

gam::Population::Population(unsigned int size) {
  if ( size > 0 ) {
    popSize = size;
    members.reserve(size);
  }
  else {
    cerr << "ERROR: Failure to construct object of 'Population'" << endl;
    cerr << "Reason: population size < 1 (" << size << ")" << endl;
  }
}

gam::Population::~Population() {
  delete popSize;
  delete members;
  }

void gam::Population::initPopulation() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members.push_back( new Individual( gam::Utility.getRandom32() ) );
  }
}

void gam::Population::evalFitness() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members[i].computeFitness();
  }
}

void sortByFitness(const Individual& i1, const Individual& i2) {
  return i1.getFitness() < i2.getFitness();
}

void gam::Population::sort() {
  sort(members.begin(), members.end(), sortByFitness);
}

Individual gam::Population::getIndividual(unsigned int pos) {
  return members[pos];
}

void gam::Population::setIndividual(unsigned int pos, Individual ind) {
  members[pos] = ind;
}

unsigned int gam::Population::getPopulationSize() {
  return popSize;
}
