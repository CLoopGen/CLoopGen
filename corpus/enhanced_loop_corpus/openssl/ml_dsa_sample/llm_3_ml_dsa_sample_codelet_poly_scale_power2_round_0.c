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
    const int stride = 16;
    for (i = 0; i < 256; i += stride) {
        for (int j = 0; j < stride && (i + j) < 256; j++) {
            int idx = i + j;
            out->coeff[idx] = (in->coeff[idx] << 13);
        }
    }
}
