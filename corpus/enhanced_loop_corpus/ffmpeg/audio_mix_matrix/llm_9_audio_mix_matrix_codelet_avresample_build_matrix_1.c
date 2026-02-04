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
    int idx;
    int total_elements = out_channels * in_channels;
    double scale = 1.0 / maxcoef;
    for (idx = 0; idx < total_elements; idx++) {
        matrix_out[idx] = (matrix_out[idx] > 0) ? (matrix_out[idx] / maxcoef) : (-(-matrix_out[idx] / maxcoef));
    }
}
