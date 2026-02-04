#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_taps;
extern float scale;
extern int dc_norm;
extern int i;
extern float *h;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; dc_norm && i < num_taps; i += 2)
        h[i] *= scale / sum;
}
