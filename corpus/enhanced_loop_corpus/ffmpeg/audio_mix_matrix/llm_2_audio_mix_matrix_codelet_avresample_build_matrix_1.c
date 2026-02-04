#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix_out;
extern int stride;
extern int i;
extern int j;
extern double maxcoef;
extern int in_channels;
extern int out_channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to column-major (j-major) order for better spatial locality if stride is large
    for (j = 0; j < in_channels; j++)
        for (i = 0; i < out_channels; i++)
            matrix_out[i * stride + j] /= maxcoef;
}
