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
    for (i = 0; i < 256; i++) {
        uint32_t temp1 = in->coeff[i] << 13;
        uint32_t temp2 = in->coeff[i] >> 7;
        uint32_t temp3 = temp1 ^ temp2;
        out->coeff[i] = temp3 + (temp3 << 3);
    }
}
