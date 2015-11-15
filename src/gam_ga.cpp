#include "gam_ga.h"

gam::GeneticAlgorithm::GeneticAlgorithm() {
  param = new Parameters();
}

gam::GeneticAlgorithm::GeneticAlgorithm(boolean isInitByFile) {
  param = new Parameters(isInitByFile);
}

gam::GeneticAlgorithm::GeneticAlgorithm(Parameters p) {
  param = p;
}

void gam::GeneticAlgorithm::initialize(boolean isInitByFile){
  param = new Parameters(isInitByFile);
}
  
FitnessType gam::GeneticAlgorithm::evolve() {
  // TODO: implement this method
  int i;
  Population pCnt,pNxt,pTmp;
  pCnt = //I think we need a getPopulation() method here.
  setParameters(param);
  while(i<param.getMaxGenerations){
    pTmp = selection(pCnt);
    pTmp = offspring(pTmp);
    evalPopulation(pTmp);
    pNxt = replacement(pCnt,pTmp);
  }
  pNxt.sort();
    
}

void gam::GeneticAlgorithm::setParameters(Parameters p) {
  param = p;
}

Parameters gam::GeneticAlgorithm::getParameters() {
  return param;
}

Population gam::GeneticAlgorithm::selection(Population p) {
  // TODO: implement this method
}

Population gam::GeneticAlgorithm::offspring(Population p) {
  // TODO: implement this method
  for (unsigned int i = 0; i < p.popSize; ++i) {
    int j = Utility.getRandom32(0,1);
    if(j<param.getMutationProb){
      p.members[i] = mutate(p.members[i]);
    }
    else{
      int k = Utility.getRandom32(0,p.popSize-1);
      k = ceil(k);
      while(k!=i){
        k = Utility.getRandom32(0,p.popSize-1);
        k = ceil(k);
      }
      p.member[i] = recombination(p.members[i],p.member[k]);
    }
  }
}

Individual gam::GeneticAlgorithm::recombination(Individual i1, 
        Individual i2) {
  // TODO: implement this method
}

Individual gam::GeneticAlgorithm::mutate(Individual i) {
  // TODO: implement this method
}

void gam::GeneticAlgorithm::evalPopulation(Population p) {
  // TODO: implement this method
  p.evaluate();
}

Population gam::GeneticAlgorithm::replacement(Population pCnt, 
        Population pTmp) {
  // TODO: implement this method
}

