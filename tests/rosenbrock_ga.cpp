#include <iostream>
#include <math.h>

#include "gam.h"

using namespace std;
using namespace gam;

double rosenbrock(double x, double y);

int main() {
  Parameters param;
  
  param.setDomain(-2, 1.0, -2, 1.0);
  param.setFitnessFunction( &rosenbrock );
  param.setMaxGenerations(1000);
  param.setPopulationSize(300);
  
  GeneticAlgorithm ga( param );
  
  ga.evolve();
  
  return 0;
}

double rosenbrock(double x, double y) {
  return pow(1 - x, 2) + ( 100 * pow( y - (x*x), 2 ) );
}

