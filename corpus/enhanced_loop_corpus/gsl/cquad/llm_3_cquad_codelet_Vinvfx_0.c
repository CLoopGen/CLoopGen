#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V1inv[25];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access Pattern via Index Array
    // Introduce an explicit index array to enable indirect addressing into fx
    // This simulates a non-uniform or computed memory access pattern.
    static const int index_map[5] = {0, 8, 16, 24, 32}; // Precomputed indices: j * 8
    for (i = 0; i <= 4; i++) {
        c[i] = 0.0;
        for (j = 0; j <= 4; j++)
            c[i] += V1inv[i * 5 + j] * fx[index_map[j]];  // Indirect access using lookup table
    }
}
