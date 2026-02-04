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
    for (i = 0; i < 128; i++) {
        out->coeff[2*i] = (in->coeff[2*i] << 13) + (in->coeff[2*i] >> 19);
        out->coeff[2*i + 1] = (in->coeff[2*i + 1] << 13) - (in->coeff[2*i + 1] >> 19);
    }
}
