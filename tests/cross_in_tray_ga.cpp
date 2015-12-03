#include <iostream>
#include <math.h>

#include "gam.h"

using namespace std;
using namespace gam;

double crossInTray(double x, double y);

int main() {
  Parameters param;
  
  param.setDomain(-2, 2, -2, 2);
  param.setFitnessFunction( &crossInTray );
  
  GeneticAlgorithm ga( param );
  
  ga.evolve();
  
  return 0;
}

double crossInTray(double x, double y) {
  return -0.0001 * pow ( abs( sin(x) * sin(y) * 
          exp( abs( 100 - ( sqrt( (x*x) + (y*y) ) / M_PI ) ) ) + 1 ), 0.1);
}

