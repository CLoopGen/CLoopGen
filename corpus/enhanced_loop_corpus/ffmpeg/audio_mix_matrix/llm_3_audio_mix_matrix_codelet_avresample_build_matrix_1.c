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
    // Variant 2: Use consecutive pointer arithmetic to traverse memory sequentially
    double *ptr = matrix_out;
    double inv_maxcoef = 1.0 / maxcoef;
    int total_elements = out_channels * stride; // Assuming full rectangular block up to last row
    for (int idx = 0; idx < total_elements; idx++, ptr++) {
        if ((idx % stride) < in_channels) // Only scale valid input channels per output
            *ptr *= inv_maxcoef;
    }
}
