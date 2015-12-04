#include <iostream>
#include <math.h>

#include "gam.h"

using namespace std;
using namespace gam;

double rosenbrock(double x, double y);

#define DOMAIN_VALUE 2.048

int main() {
  Parameters param;
  
  param.setDomain(-DOMAIN_VALUE, DOMAIN_VALUE, -DOMAIN_VALUE, DOMAIN_VALUE);
  param.setFitnessFunction( &rosenbrock );
  param.setMaxGenerations(10000);
  param.setPopulationSize(250);
  param.setMutationProb(0.25);
  param.setOutputFilePrefix("rosenbrock");
  
  GeneticAlgorithm ga( param );
  
  ga.evolve();
  
  return 0;
}

double rosenbrock(double x, double y) {
  return pow(1 - x, 2) + ( 100 * pow( y - (x*x), 2 ) );
}

