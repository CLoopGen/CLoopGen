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
    for (i = 0; i < N; i++) {
        int idx1 = 2 * iy;
        int idx2 = 2 * iy + 1;
        ((double *)Y)[idx1] = 0.0;
        ((double *)Y)[idx2] = 0.0;
        ((double *)Y)[idx1 + 2] = 1.0;  // Additional computation: write to next even index
        ((double *)Y)[idx2 + 2] = 1.0;  // Additional computation: write to next odd index
        iy += incY;
    }
}
