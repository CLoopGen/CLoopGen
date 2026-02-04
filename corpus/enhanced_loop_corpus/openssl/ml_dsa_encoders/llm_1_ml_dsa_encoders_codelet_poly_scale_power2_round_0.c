#include <stdio.h>

#include <inttypes.h>

struct poly_st {
    uint32_t coeff[256];
};


typedef struct poly_st POLY;

extern POLY *in;
extern POLY *out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    out->coeff[i*4+0] = (in->coeff[i*4+0] << 13);
    out->coeff[i*4+1] = (in->coeff[i*4+1] << 13);
    out->coeff[i*4+2] = (in->coeff[i*4+2] << 13);
    out->coeff[i*4+3] = (in->coeff[i*4+3] << 13);
}
}
