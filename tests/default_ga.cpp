#include <iostream>
#include "gam.h"

using namespace std;
using namespace gam;

int main() {
  GeneticAlgorithm ga;

  Utility::initRandNumberGen();

// Random Number Generator is working fine! :D

  for( int i = 0; i < 10; i++ )
    cout << Utility::getRandomF64() << endl;


//  ga.evolve();
  
  return 0;
}

