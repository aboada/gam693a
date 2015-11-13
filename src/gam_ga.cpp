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

FitnessType gam::GeneticAlgorithm::evolve() {
  // TODO: implement this method
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

Population gam::GeneticAlgorithm::recombination(Population p) {
  // TODO: implement this method
}

void gam::GeneticAlgorithm::evalPopulation(Population p) {
  // TODO: implement this method
}

Population gam::GeneticAlgorithm::replacement(Population pCnt, 
        Population pTmp) {
  // TODO: implement this method
}

