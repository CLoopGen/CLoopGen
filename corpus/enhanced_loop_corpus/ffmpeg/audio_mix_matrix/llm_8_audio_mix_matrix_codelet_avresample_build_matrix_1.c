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
    int i, j;
    double scale = 1.0 / maxcoef;
    for (i = 0; i < out_channels; i++) {
        int offset = i * stride;
        for (j = 0; j < in_channels; j++) {
            matrix_out[offset + j] *= scale;
        }
    }
}
