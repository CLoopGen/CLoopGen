#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    FLOAT8 *sf_ptr = sf + 11;
    int *pretab_ptr = pretab + 11;
    for (int i = 0; i < 10; i++) {
        sf_ptr[i] += pretab_ptr[i] / ifqstep_inv;
    }
}
