#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double R[1200][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using linear indexing - treat 2D array as 1D for better spatial locality
    int idx;
    for (idx = 0; idx < n * n; idx++) {
        R[idx / 1200][idx % 1200] = 0.;
    }
}
