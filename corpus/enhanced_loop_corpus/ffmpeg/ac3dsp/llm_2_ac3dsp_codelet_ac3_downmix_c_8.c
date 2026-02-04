#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern float **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern float v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing samples[j][i] with j varying and i fixed (column-major-like),
    // we maintain the same logic but simulate a strided access by stepping through memory
    // in a non-unit stride manner for the matrix row, though layout remains the same.
    // Here, we emphasize access to matrix[0][j] with unit stride and samples[j][i] as indirect base + offset.
    for (i = 0; i < len; i++) {
        v0 = 0.F;
        float *sample_row = samples[0]; // Reuse target row base
        for (j = 0; j < in_ch; j++) {
            // Access samples[j][i] as if traversing different arrays at fixed offset i
            // This creates a scattered read pattern across different rows j at same column i
            v0 += samples[j][i] * matrix[0][j];
        }
        sample_row[i] = v0;
    }
}
