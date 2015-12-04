#ifndef GAM_INCLUDE_PARAMETERS_H_
#define GAM_INCLUDE_PARAMETERS_H_

#include <tuple>
#include <string>
 
#include "gam_definitions.h"

#define DEFAULT_POP_SIZE          ( 300 )
#define DEFAULT_MAX_GEN           ( 10000 )
#define DEFAULT_GENERATIONAL_GAP  (0.3)
#define DEFAULT_MUTATION_PROB     (0.1)
#define DEFAULT_BIT_MUTATION_PROB (0.2)
#define DEFAULT_X_MIN             (0.0)
#define DEFAULT_X_MAX             (1.0)
#define DEFAULT_Y_MIN             (0.0)
#define DEFAULT_Y_MAX             (1.0)
#define DEFAULT_OUTPUT_F_PREFIX   ("results")

namespace gam {
  
  using namespace std;
  
  class Parameters {
    private:
      unsigned int popSize;
      unsigned int maxGenerations;
      double generationalGap;
      double mutationProb;
      double bitMutationProb;
      pair<double, double> domainX, domainY;
      string outputPrefix;
      
    public:
      Parameters();
      Parameters(bool isInitByFile);
      void initByDefault();
      void initByFile();
      unsigned int getPopulationSize();
      unsigned int getMaxGenerations();
      double getGenerationalGap();
      unsigned int getNPreservedIndividuals();
      unsigned int getNReplacedIndividuals();
      double getMutationProb();
      double getBitMutationProb();
      void setPopulationSize(unsigned int size);
      void setMaxGenerations(unsigned int max);
      void setGenerationalGap(double gap);
      void setMutationProb(double prob);
      void setBitMutationProb(double prob);
      void setDomain(double xMin, double xMax, double yMin, double yMax);
      void setDomainX(double xMin, double xMax);
      void setDomainY(double yMin, double yMax);
      void setFitnessFunction( double (*function)(double x, double y) );
      double getMinX();
      double getMaxX();
      double getMinY();
      double getMaxY();
      double (*fitnessFunction)(double x, double y);
      void setOutputFilePrefix(string prefix);
      string getOutputFilePrefix();
  };
  
}

#endif // GAM_INCLUDE_PARAMETERS_H_
