#include "gam_ga.h"
#include "gam_utility.h"
#include <math.h>
#include <bitset>

using namespace gam;

GeneticAlgorithm::GeneticAlgorithm() {
  param = new Parameters();
}

GeneticAlgorithm::GeneticAlgorithm(bool isInitByFile) {
  param = new Parameters(isInitByFile);
}

GeneticAlgorithm::GeneticAlgorithm(Parameters p) {
  param = p;
}

void GeneticAlgorithm::initialize(bool isInitByFile){
  param = new Parameters(isInitByFile);
}
  
FitnessType GeneticAlgorithm::evolve() {
  // TODO: implement this method
  int i;
  Population pCnt,pTmp,pNxt;
  setParameters(param);
  while(i<param.getMaxGenerations()){
    pTmp = selection(pCnt);
    pTmp = offspring(pTmp);
    evalPopulation(pTmp);
    pNxt = replacement(pCnt,pTmp);
  }
  pNxt.sort();
    
}

void GeneticAlgorithm::setParameters(Parameters p) {
  param = p;
}

Parameters GeneticAlgorithm::getParameters() {
  return param;
}

Population GeneticAlgorithm::selection(Population p) {
  // TODO: implement this method
}

Population GeneticAlgorithm::offspring(Population p) {
  // TODO: implement this method
  for (unsigned int pos1 = 0; pos1 < p.getPopulationSize(); ++pos1) {
    int j = Utility::getRandom32(0,1);
    if(j<param.getMutationProb()){
      p.getIndividual(pos1) = mutate(p.getIndividual(pos1));
    }
    else{
      int pos2 = Utility::getRandom32(0,p.getPopulationSize()-1);
      pos2 = ceil(pos2);
      while(pos2==pos1){
        pos2 = Utility::getRandom32(0,p.getPopulationSize()-1);
        pos2 = ceil(pos2);
      }
      p.getIndividual(pos1) = recombination(p.getIndividual(pos1),
                              p.getIndividual(pos2));
    }
  }
}

Individual GeneticAlgorithm::recombination(Individual i1, 
        Individual i2) {
  // TODO: implement this method
}

Individual GeneticAlgorithm::mutate(Individual i) {
  // READY FOR USE: 
  unsigned int  size = sizeof(i.getChromosome().bitArray);
  std::bitset <32> bits(i.getChromosome().bitArray);
  for(int pos=0; pos < size ; pos++){
    int prob = Utility::getRandom32(0,1);
    if(prob < param.getBitMutationProb()){
      bits.flip(pos);
    }
  }
  i.setChromosome((unsigned int) bits.to_ulong()) ;
  return i;
}

void GeneticAlgorithm::evalPopulation(Population p) {
  // TODO: implement this method
  p.evalFitness();
}

Population GeneticAlgorithm::replacement(Population pCnt, 
        Population pTmp) {
  // TODO: implement this method
}

int main() {}
