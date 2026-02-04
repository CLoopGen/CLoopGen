#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 (access every other element)
    for (sfb = 11; sfb < 21; sfb += 2) {
        sf[sfb] += pretab[sfb] / ifqstep_inv;
        if (sfb + 1 < 21) {
            sf[sfb + 1] += pretab[sfb + 1] / ifqstep_inv;
        }
    }
}
