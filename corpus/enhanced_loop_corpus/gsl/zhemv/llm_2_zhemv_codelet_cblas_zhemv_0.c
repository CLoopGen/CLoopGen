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
    // Variant 1: Consecutive memory access by reindexing to eliminate multiplication
    int base_idx = 0;
    for (i = 0; i < N; i++) {
        ((double *)Y)[base_idx]     = 0.;
        ((double *)Y)[base_idx + 1] = 0.;
        base_idx += 2 * incY;
    }
}
