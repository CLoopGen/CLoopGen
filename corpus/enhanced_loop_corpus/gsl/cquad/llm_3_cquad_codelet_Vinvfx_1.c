#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V2inv[81];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Indirect Indexing
    // Use an index array to introduce indirect memory access for V2inv
    // This simulates a non-unit stride or scatter-gather pattern
    int idx[9];
    for (int k = 0; k < 9; k++) {
        idx[k] = k * 9;  // Precompute row start indices for V2inv
    }
    for (i = 0; i <= 8; i++) {
        c[i] = 0.;
        for (j = 0; j <= 8; j++)
            c[i] += V2inv[idx[i] + j] * fx[j * 4];  // Indirect access via precomputed base index
    }
}
