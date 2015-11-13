#include <math.h>
#include <float.h>
#include "gam_individual.h"


#define GAM_INIT_X_VAL 10
#define GAM_INIT_Y_VAL 10
#define FUNC(x,y) 100*(pow((y-pow(x,2)),2))+(pow((1-x),2))
#define FITNESS_MAX_VALUE DBL_MAX

using namespace gam;

Individual::Individual(uint32 b){
	fitness = FITNESS_MAX_VALUE;
	chrome.bitarray = b;		
}	

Individual::Individual(){
	fitness = DBL_MAX;
	chrome.info.xcomponent = GAM_INIT_X_VAL;
	chrome.info.ycomponent = GAM_INIT_Y_VAL;	
}
		
void Individual::computeFitness(){
	FitnessType x,y;
	
  // TODO: Fix this, chrome.info._component should be decoded first 
	x = chrome.info.xcomponent; 
	y = chrome.info.ycomponent; 

	fitness = FUNC(x,y);
}

FitnessType Individual::getFitness(){
	return fitness;
}
	
void Individual::setChromosome(chromosome ch){
	chrome = ch;
}
	
void Individual::setChromosome(uint32 b){
	chrome.bitarray = b;
}

chromosome Individual::getChromosome(){
	return chrome;
}




