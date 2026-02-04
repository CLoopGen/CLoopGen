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
        uint32_t temp1 = in->coeff[2*i];
        uint32_t temp2 = in->coeff[2*i + 1];
        out->coeff[2*i]     = ((temp1 << 13) ^ (temp1 >> 19)) + 0x12345678U;
        out->coeff[2*i + 1] = ((temp2 << 13) ^ (temp2 >> 19)) + 0x87654321U;
    }
}
