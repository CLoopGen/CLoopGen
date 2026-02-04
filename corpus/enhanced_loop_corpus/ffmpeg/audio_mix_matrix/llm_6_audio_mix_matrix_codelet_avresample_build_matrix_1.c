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
    double temp;
    for (i = 0; i < out_channels; i++) {
        temp = 0.0;
        for (j = 0; j < in_channels; j++) {
            temp = matrix_out[i * stride + j] / maxcoef;
            matrix_out[i * stride + j] = temp;
        }
    }
}
