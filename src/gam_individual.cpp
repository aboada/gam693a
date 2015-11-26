#include <math.h>
#include <float.h>
#include "gam_individual.h"

#define GAM_INIT_X_VAL            10
#define GAM_INIT_Y_VAL            10
#define ROSENBROCK(x,y)           100*((y-(x*x)*(y-(x*x)))+((1-x)*(1-x)))
#define FITNESS_FUNCTION(x,y)     ROSENBROCK(x,y)
#define FITNESS_MAX_VALUE         DBL_MAX
#define BITS_TO_DOUBLE(n,bits)    ((double) (n/(pow(2,bits)-1)))

using namespace gam;

Individual::Individual(uint32 b){
  fitness = FITNESS_MAX_VALUE;
  chrome.bitarray = b;		
}	

Individual::Individual(){
  fitness = DBL_MAX;
  chrome.info.xComponent = GAM_INIT_X_VAL;
  chrome.info.yComponent = GAM_INIT_Y_VAL;	
}
		
void Individual::computeFitness(){
  FitnessType x,y;
  int bits = sizeof(uint32) / 2;
  x = BITS_TO_DOUBLE(chrome.info.xComponent,bits); 
  y = BITS_TO_DOUBLE(chrome.info.yComponent,bits);  
  fitness = FITNESS_FUNCTION(x,y);
}

FitnessType Individual::getFitness(){
  return fitness;
}
	
void Individual::setChromosome(Chromosome ch){
  chrome = ch;
}
	
void Individual::setChromosome(uint32 b){
  chrome.bitarray = b;
}

Chromosome Individual::getChromosome(){
  return chrome;
}

 

