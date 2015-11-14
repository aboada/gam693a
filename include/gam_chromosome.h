#define GAM_X_COMPONENT 16
#define GAM_Y_COMPONENT 16

typedef unsigned int uint32;


typedef struct {
  uint32	xComponentBits : GAM_X_COMPONENT;
  uint32	yComponentBits : GAM_Y_COMPONENT;
} Gene ;


typedef union {
  uint32	bitarray;
  Gene 	  info;
} Chromosome; 
