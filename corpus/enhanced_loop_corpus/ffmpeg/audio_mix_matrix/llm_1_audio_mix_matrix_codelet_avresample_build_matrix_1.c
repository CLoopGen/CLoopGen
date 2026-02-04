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
for (i = 0; i < out_channels; i++) {
    double *row_start = &matrix_out[i * stride];
    for (j = 0; j < in_channels; j++) {
        row_start[j] /= maxcoef;
    }
}
}
