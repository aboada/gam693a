#include <iostream>
#include <math.h>

#include "gam.h"

using namespace std;
using namespace gam;

double eggholder(double x, double y);

#define DOMAIN_VALUE (512)

int main() {
  Parameters param;
  
  param.setDomain(-DOMAIN_VALUE, DOMAIN_VALUE, -DOMAIN_VALUE, DOMAIN_VALUE);
  param.setFitnessFunction( &eggholder );
  param.setMaxGenerations(1000);
  param.setPopulationSize(300);
  param.setMutationProb(0.40);
  param.setOutputFilePrefix("eggholder");
  
  GeneticAlgorithm ga( param );
  
  ga.evolve();
  
  return 0;
}

double eggholder(double x, double y) {
  return - (y+47) * sin(sqrt(abs(y+(x/2)+47))) - (x*sin(sqrt(abs(x-(y+47)))));
}

