#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with explicit stride scaling and precomputed pointer
    double *Yd = (double *)Y;
    int stride = 2 * incY;
    int idx = 0;
    for (i = 0; i < N; i++) {
        Yd[idx]       = 0.;
        Yd[idx + 1]   = 0.;
        idx          += stride;
    }
}
