#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride on pretab
    // Instead of sequential sfb index, access every 2nd element starting from offset
    int stride = 2;
    for (sfb = 11; sfb < 21; sfb += stride) {
        int idx = sfb; // Logical index still used, but could be mapped differently
        if (sf[idx] + pretab[idx] / ifqstep_inv > 0)
            break;
    }
}
