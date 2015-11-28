#include "gam_parameters.h"

using namespace gam;

Parameters::Parameters() {
  popSize = DEFAULT_POP_SIZE;
  maxGenerations = DEFAULT_MAX_GEN;
  generationalGap = DEFAULT_GENERATIONAL_GAP;
  mutationProb = DEFAULT_MUTATION_PROB;
  bitMutationProb = DEFAULT_BIT_MUTATION_PROB;
}

Parameters::Parameters(bool isInitByFile) {
  if ( isInitByFile ) 
    initByFile();
  else 
    initByDefault();
}

void Parameters::initByDefault() {
  popSize = DEFAULT_POP_SIZE;
  maxGenerations = DEFAULT_MAX_GEN;
  generationalGap = DEFAULT_GENERATIONAL_GAP;
  mutationProb = DEFAULT_MUTATION_PROB;
  bitMutationProb = DEFAULT_BIT_MUTATION_PROB;
}

void Parameters::initByFile() {
  //TODO: Implement this method.
  // using initByDefault for now.
  initByDefault();
}

unsigned int Parameters::getPopulationSize() {
  return popSize;
}

unsigned int Parameters::getMaxGenerations() {
  return maxGenerations;
}

double Parameters::getGenerationalGap() {
  return generationalGap;
}

unsigned int Parameters::getNPreservedIndividuals() {
  return (unsigned int) ( popSize * generationalGap );
}

unsigned int Parameters::getNReplacedIndividuals() {
  return (unsigned int) ( popSize * (1 - generationalGap) );
}

double Parameters::getMutationProb() {
  return mutationProb;
}

double Parameters::getBitMutationProb() {
  return bitMutationProb;
}

void Parameters::setPopulationSize(unsigned int size) {
  if ( size >= MIN_POP_SIZE )
    popSize = size;
}

void Parameters::setMaxGenerations(unsigned int max) {
  if ( max >= MIN_GENERATIONS ) 
    maxGenerations = max;
}

void Parameters::setGenerationalGap(double gap) {
  if ( gap >= 0.0 && gap < 1.0 ) 
    generationalGap = gap;
}

void Parameters::setMutationProb(double prob) {
  if ( prob >= 0.0 && prob < 1.0 ) 
    mutationProb = prob;
}

void Parameters::setBitMutationProb(double prob) {
  if ( prob > 0.0 && prob < 1.0 ) 
    bitMutationProb = prob;
}

