#define GAM_X_COMPONENT 16
#define GAM_Y_COMPONENT 16

typedef unsigned int uint32;


typedef struct {
	uint32	xcomponent : GAM_X_COMPONENT;
	uint32	ycomponent : GAM_Y_COMPONENT;
} gene ;


typedef union {
	uint32	bitarray;
	gene 	  info;
} chromosome; 
