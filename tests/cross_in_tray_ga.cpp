#include <iostream>
#include <math.h>

#include "gam.h"

using namespace std;
using namespace gam;

double crossInTray(double x, double y);

#define DOMAIN_VALUE 2.048

int main() {
  Parameters param;
  
  param.setDomain(-DOMAIN_VALUE, DOMAIN_VALUE, -DOMAIN_VALUE, DOMAIN_VALUE);
  param.setFitnessFunction( &crossInTray );
  param.setMaxGenerations(10000);
  param.setPopulationSize(250);
  param.setMutationProb(0.25);
  
  GeneticAlgorithm ga( param );
  
  ga.evolve();
  
  return 0;
}

double crossInTray(double x, double y) {
  return -0.0001 * pow ( abs( sin(x) * sin(y) * 
          exp( abs( 100 - ( sqrt( (x*x) + (y*y) ) / M_PI ) ) ) + 1 ), 0.1);
}

