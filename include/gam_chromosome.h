#include "gam_definitions.h"
#include "gam_utility.h"

typedef struct {

  uint32 xComponent : GAM_X_COMPONENT_BITS;
  uint32 yComponent : GAM_Y_COMPONENT_BITS;
  
} Gene;


typedef union {

  uint32 bitArray;
  Gene 	 info;
  
} Chromosome;

