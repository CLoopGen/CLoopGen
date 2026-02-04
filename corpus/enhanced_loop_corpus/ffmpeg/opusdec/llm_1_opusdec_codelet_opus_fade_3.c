#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in1;
extern  float *in2;
extern  float *window;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer, inner;
    int block_size = 16;
    for (outer = 0; outer < len; outer += block_size) {
        for (inner = outer; inner < len && inner < outer + block_size; inner++) {
            i = inner;
            out[i] = in2[i] * window[i] + in1[i] * (1. - window[i]);
        }
    }
}
