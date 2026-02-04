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
    for (i = 0; i < 128; i += 2) {
        out->coeff[i] = (in->coeff[i] << 13) + (in->coeff[i] >> 5);
        if (i + 1 < 256) {
            out->coeff[i + 1] = (in->coeff[i + 1] << 13) + (in->coeff[i + 1] >> 5);
        }
    }
}
