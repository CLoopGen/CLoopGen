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
    for (i = 0; i < 256; i += 4) {
        out->coeff[i]     = (in->coeff[i] << 13);
        out->coeff[i + 1] = (in->coeff[i + 1] << 13);
        out->coeff[i + 2] = (in->coeff[i + 2] << 13);
        out->coeff[i + 3] = (in->coeff[i + 3] << 13);
    }
}
