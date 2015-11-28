#include "gam_individual.h"

using namespace std;
using namespace gam;

Individual::Individual(uint32 b) {
  fitness = FITNESS_MAX_VALUE;
  chrome.bitArray = b;		
}	

Individual::Individual() {
  fitness = DBL_MAX;
  
  chrome.info.xComponent = GAM_INIT_X_VAL;
  chrome.info.yComponent = GAM_INIT_Y_VAL;	
}
		
void Individual::computeFitness(){
  FitnessType x, y;
  
  x = BITS_TO_DOUBLE( chrome.info.xComponent, GAM_X_COMPONENT_BITS ); 
  y = BITS_TO_DOUBLE( chrome.info.yComponent, GAM_Y_COMPONENT_BITS );  
  
  fitness = FITNESS_FUNCTION( x, y );
}

FitnessType Individual::getFitness(){
  return fitness;
}
	
void Individual::setChromosome(Chromosome ch){
  chrome = ch;
}
	
void Individual::setChromosome(uint32 b){
  chrome.bitArray = b;
}

Chromosome Individual::getChromosome(){
  return chrome;
}

// Single point crossover
Individual Individual::crossover(Individual parent) {
  unsigned int xPoint, nBits;
  uint32 chThis, chParent, mask, off;
  
  chThis = getChromosome().bitArray;
  chParent = parent.getChromosome().bitArray;
  
  nBits = sizeof( uint32 );
  
  xPoint = Utility::getRandomUI32(0, nBits);
  
  mask = ~0 >> xPoint;
  
  if ( Utility::getRandomF64() < 0.5 ) 
    off = ( chThis & ~mask ) | ( chParent &  mask );
  else
    off = ( chThis &  mask ) | ( chParent & ~mask );
  
  return Individual( off );
}

void Individual::mutate(double bitMutationProb) {
  unsigned int size = GAM_BIT_ARRAY_SIZE;

  std::bitset<GAM_BIT_ARRAY_SIZE> bits( getChromosome().bitArray );
  
  for (unsigned int pos = 0; pos < size ; pos++) {
    double prob = Utility::getRandomF64();
    
    if( prob < bitMutationProb )
      bits.flip(pos);
  }
  
  chrome.bitArray = ( uint32 ) bits.to_ulong();
}

Individual Individual::operator = (Individual other) {
  swap( fitness, other.fitness );
  swap( chrome.bitArray, other.chrome.bitArray );
  
  return *this;
}

bool Individual::operator < ( const Individual& other ) {
  return ( fitness < other.fitness );
}

