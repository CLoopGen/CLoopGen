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
for (i = 0; i < out_channels * in_channels; i++) {
    int local_i = i / in_channels;
    int local_j = i % in_channels;
    matrix_out[local_i * stride + local_j] /= maxcoef;
}
}
