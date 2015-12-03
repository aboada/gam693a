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
		
void Individual::computeFitness(const Parameters &p) {
  Parameters param = p;
  double x, y;
  
  x = BITS_TO_DOUBLE( chrome.info.xComponent, GAM_X_COMPONENT_BITS,
            param.getMinX(), param.getMaxX() ); 
  y = BITS_TO_DOUBLE( chrome.info.yComponent, GAM_Y_COMPONENT_BITS, 
            param.getMinY(), param.getMaxY() );  
  
  fitness = param.fitnessFunction( x, y );
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

void Individual::setFitness(FitnessType f) {
  fitness = f;
}

Individual Individual::operator = (Individual other) {
  swap( fitness, other.fitness );
  swap( chrome.bitArray, other.chrome.bitArray );
  
  return *this;
}

bool Individual::operator < ( const Individual& other ) {
  return ( fitness < other.fitness );
}

void Individual::print(bool computeFitness, const Parameters &p) {
  Parameters param = p;
  FitnessType funcEval = fitness;
  double x, y;
  
  x = BITS_TO_DOUBLE( chrome.info.xComponent, GAM_X_COMPONENT_BITS,
            param.getMinX(), param.getMaxX() ); 
  y = BITS_TO_DOUBLE( chrome.info.yComponent, GAM_Y_COMPONENT_BITS, 
            param.getMinY(), param.getMaxY() );  
  
  if ( computeFitness)
    funcEval = param.fitnessFunction( x, y );
  
  cout << "(" << x << "," << y << ") = " << funcEval << endl;  
}

