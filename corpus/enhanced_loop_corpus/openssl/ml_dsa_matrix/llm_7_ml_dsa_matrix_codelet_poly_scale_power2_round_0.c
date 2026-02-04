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
    uint32_t prev = 0;
    for (i = 0; i < 256; i++) {
        uint32_t current = (in->coeff[i] << 13) ^ prev;
        out->coeff[i] = current;
        prev = current;
    }
}
