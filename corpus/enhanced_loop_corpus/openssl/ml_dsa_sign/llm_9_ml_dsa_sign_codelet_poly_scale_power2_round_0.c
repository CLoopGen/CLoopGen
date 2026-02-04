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
        uint32_t temp1 = in->coeff[i] << 13;
        uint32_t temp2 = in->coeff[255 - i] >> 13;
        out->coeff[i] = temp1 ^ temp2;
        out->coeff[255 - i] = temp1 + temp2;
    }
}
