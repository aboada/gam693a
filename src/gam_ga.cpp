#include "gam_ga.h"
#include "gam_utility.h"
#include <math.h>
#include <bitset>

using namespace gam;

GeneticAlgorithm::GeneticAlgorithm() {
  param = Parameters();
}

GeneticAlgorithm::GeneticAlgorithm(bool isInitByFile) {
  param = Parameters(isInitByFile);
}

GeneticAlgorithm::GeneticAlgorithm(Parameters p) {
  param = p;
}

void GeneticAlgorithm::initialize(bool isInitByFile){
  param = Parameters(isInitByFile);
}
  
FitnessType GeneticAlgorithm::evolve() {
  unsigned int i, maxGen;
  
  maxGen = param.getMaxGenerations();
  
  Population pCnt, pTmp, pNxt;
  
  for (i = 0; i < maxGen; i++) {
  
    pTmp = selection(pCnt);
    pTmp = offspring(pTmp);
    evalPopulation(pTmp);
    pCnt = replacement(pCnt,pTmp);
    pCnt.sort();
  }
  
  return pCnt.getIndividual(0).getFitness();
}

void GeneticAlgorithm::setParameters(Parameters p) {
  param = p;
}

Parameters GeneticAlgorithm::getParameters() {
  return param;
}

Population GeneticAlgorithm::selection(Population p) {
  // Using SUS method: Stochastic Universal Sampling
  // https://en.wikipedia.org/wiki/Stochastic_universal_sampling
  
  Population tmp;
  unsigned int selected, nSelect, popSize;
  double increment, mark, adaptSum;
  
  nSelected = param.getNReplacedIndividuals();
  increment = 1.0 / nSelected;
  mark = increment * Utility::getRandom64f();
  popSize = p.getPopulationSize();
  selected = 0;
  adaptSum = 0.0;
  
  p.sort();
  
  for (unsigned int i = 0; i < popSize && selected < nSelect; i++) {
    adaptSum += p.getIndividual(i).getFitness();
    
    while ( adaptSum > mark ) {
      tmp.addIndividual( p.getIndividual(i) );
      mark += increment;
      selected++;
    }
  }
  
  for (unsigned int i = 0; selected < nSelect; i++, selected++)
    tmp.addIndividual( p.getIndividual(i) );
  
  return tmp;
}

Population GeneticAlgorithm::offspring(Population p) {
  Population pTmp;
  unsigned int popSize = p.getPopulationSize();

  for (unsigned int pos1 = 0; pos1 < popSize; ++pos1) {
    Individual ind = p.getIndividual(pos1);
    float prob = Utility::getRandom32(0,1);
    
    if ( prob < param.getMutationProb() ) 
      ind.mutate();
    else {
      unsigned int pos2 = Utility::getRandom32UI(0, popSize - 1);
      
      while ( pos2 == pos1 )
        pos2 = Utility::getRandom32UI(0, popSize - 1);
      
      ind = ind & p.getIndividual( pos2 );
    }
    
    pTmp.addIndividual( ind );
  }
  
  return pTmp;
}

void GeneticAlgorithm::evalPopulation(Population &p) {
  p.evalFitness();
  p.sort();
}

Population GeneticAlgorithm::replacement(const Population &pCnt, 
        const Population &pTmp) {
  Population pNxt;
  unsigned int nReplaced, nPreserved;
  
  nReplaced = param.getNReplacedIndividuals();
  nPreserved = param.getNPreservedIndividuals();
  
  for ( unsigned int i = 0; i < nPreserved; i++) 
    pNxt.addIndividual( pCnt.getIndividual(i) );
  
  for ( unsigned int i = 0; i < nReplaced; i++) 
    pNxt.addIndividual( pTmp.getIndividual(i) );
  
  return pNxt;
}

