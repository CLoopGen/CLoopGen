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
extern float v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing samples[j][i] consecutively in the inner loop, we maintain the same computation
    // but change access pattern by precomputing base pointers and using strided access via pointer arithmetic.
    float *sample_row;
    float *matrix_row0 = matrix[0];
    float *matrix_row1 = matrix[1];
    float *sample_col0 = samples[0];
    float *sample_col1 = samples[1];

    for (i = 0; i < len; i++) {
        v0 = v1 = 0.F;
        for (j = 0; j < in_ch; j++) {
            sample_row = samples[j];  // Access column i of channel j using stride across rows
            v0 += sample_row[i] * matrix_row0[j];
            v1 += sample_row[i] * matrix_row1[j];
        }
        sample_col0[i] = v0;
        sample_col1[i] = v1;
    }
}
