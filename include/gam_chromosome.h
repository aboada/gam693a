#define GAM_X_COMPONENT_BITS 16
#define GAM_Y_COMPONENT_BITS 16

typedef unsigned int uint32;


typedef struct {
  uint32	xComponent : GAM_X_COMPONENT_BITS;
  uint32	yComponent : GAM_Y_COMPONENT_BITS;
} Gene ;


typedef union {
  uint32	bitArray;
  Gene 	  info;
} Chromosome; 
