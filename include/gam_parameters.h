#ifndef GAM_INCLUDE_PARAMETERS_H_
#define GAM_INCLUDE_PARAMETERS_H_

namespace gam {
  
  class Parameters {
    private:
      unsigned int popSize;
      unsigned int maxGenerations;
      double generationalGap;
      double mutationProb;
      double bitMutationProb;
    
    public:
      Parameters();
      Parameters(boolean isInitByFile);
      void initByDefault();
      void initByFile();
      unsigned int getPopulationSize();
      unsigned int getMaxGenerations();
      double getGenerationalGap();
      double getMutationProb();
      double bitMutationProb();
      void setPopulationSize(unsigned int size);
      void setMaxGenerations(unsigned int max);
      void setGenerationalGap(double gap);
      void setMutationProb(double prob);
      void setBitMutationProb(double prob);
  };
  
}

#endif // GAM_INCLUDE_PARAMETERS_H_
