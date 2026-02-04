#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *a;
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base index and using pointer arithmetic
    size_t idx = nc - 1;
    double *base_m = m + idx;
    double inv_a_nc = -1.0 / a[nc];
    for (i = 0; i < nc; i++) {
        base_m[i * nc] = inv_a_nc * a[i];
    }
}
