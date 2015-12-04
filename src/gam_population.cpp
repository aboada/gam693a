#include "gam_population.h"

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

void Population::initialize() {
  if ( popSize < 1 )
    return;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members.push_back( Individual( Utility::getRandomUI32() ) );
  }
}

void Population::initialize(unsigned int size) {
  popSize = max(size, (unsigned int) 0);
  
  initialize();
}

void Population::evaluate(const Parameters &p) {
  if ( popSize < 1 )
    return;
    
  Parameters param = p;
    
  for (unsigned int i = 0; i < popSize; ++i) {
    members[i].computeFitness( param );
  }
}

bool Population::sortByFitness(const Individual& i1, const Individual& i2) {
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

void Population::addIndividual(Individual ind) {
  members.push_back(ind);
  popSize = members.size();
}

void Population::print(const Parameters &p) {
  Parameters param = p;
  
  for (unsigned int i = 0; i < popSize; i++) {
    cout << i << ": ";
    members[i].print(true, param);
  }
}

void Population::rescale() {
  FitnessType sum;
  
  for(unsigned int i = 0; i < popSize; i++) 
    sum += members[i].getFitness();

  for(unsigned int i = 0; i < popSize; i++)
    members[i].setFitness( members[i].getFitness() / sum );
}

void Population::printToFile(const Parameters &p, bool isDetail) {  
  Parameters param = p;
  fstream fs;
  string filename;
  
  if ( isDetail ) {
    filename = "_detail.out";
    filename = param.getOutputFilePrefix() + filename;
  
    fs.open ( filename, fstream::in | fstream::out | fstream::app );
    
    // printing in comma-separated values (CSV)
    for (unsigned int i = 0; i < popSize; i++) {
      double x, y;
  
      x = BITS_TO_DOUBLE( members[i].getChromosome().info.xComponent, 
                GAM_X_COMPONENT_BITS,
                param.getMinX(), param.getMaxX() ); 
      y = BITS_TO_DOUBLE( members[i].getChromosome().info.yComponent, 
                GAM_Y_COMPONENT_BITS, 
                param.getMinY(), param.getMaxY() );  
    
      fs << x << "," << y << "," << members[i].getFitness() << endl;
    }
  }
  else {
    double sum = 0.0;
    filename = "_summary.out";
    filename = param.getOutputFilePrefix() + filename;
  
    fs.open ( filename, fstream::in | fstream::out | fstream::app );
    
    for (unsigned int i = 0; i < popSize; i++) 
      sum += members[i].getFitness();

    // printing in comma-separated values (CSV)
    fs << members.front().getFitness() << "," <<
            members.back().getFitness() << "," <<
            sum / popSize << endl;
  }
  
  fs.close();
}

