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
    double *local_out = matrix_out;
    int index;
    for (i = 0; i < out_channels; i++) {
        for (j = 0; j < in_channels; j++) {
            index = i * stride + j;
            // Introduce artificial WAW and WAR by splitting the update
            local_out[index] = local_out[index] / maxcoef;
        }
    }
}
