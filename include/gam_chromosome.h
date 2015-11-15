#define GAM_X_COMPONENT_BITS 16
#define GAM_Y_COMPONENT_BITS 16

typedef unsigned int uint32;


typedef struct {
<<<<<<< HEAD
  uint32	xComponent : GAM_X_COMPONENT_BITS;
  uint32	yComponent : GAM_Y_COMPONENT_BITS;
=======
  uint32  xComponentBits : GAM_X_COMPONENT;
  uint32  yComponentBits : GAM_Y_COMPONENT;
>>>>>>> 952af799b4d4e64a036aca200c6c96104c781954
} Gene ;


typedef union {
<<<<<<< HEAD
  uint32	bitArray;
  Gene 	  info;
=======
  uint32  bitarray;
  Gene    info;
>>>>>>> 952af799b4d4e64a036aca200c6c96104c781954
} Chromosome; 
