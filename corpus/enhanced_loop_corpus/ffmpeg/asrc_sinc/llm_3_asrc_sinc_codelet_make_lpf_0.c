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
    // Variant 2: Reverse consecutive memory access
    for (i = num_taps - 1; dc_norm && i >= 0; i--)
        h[i] *= scale / sum;
}
