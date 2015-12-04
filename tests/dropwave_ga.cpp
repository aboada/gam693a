#include <iostream>
#include <math.h>

#include "gam.h"

using namespace std;
using namespace gam;

double dropwave(double x, double y);

#define DOMAIN_VALUE (5.12)

int main() {
  Parameters param;
  
  param.setDomain(-DOMAIN_VALUE, DOMAIN_VALUE, -DOMAIN_VALUE, DOMAIN_VALUE);
  param.setFitnessFunction( &dropwave );
  param.setMaxGenerations(500);
  param.setPopulationSize(250);
  param.setMutationProb(0.25);
  param.setOutputFilePrefix("dropwave");
  
  GeneticAlgorithm ga( param );
  
  ga.evolve();
  
  return 0;
}

double dropwave(double x, double y) {
  return - (1+cos(12*sqrt((x*x)+(y*y)))) / ((0.5*((x*x)+(y*y)))+2);
}

