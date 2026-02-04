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
    // Variant 2: Reverse sequential access
    // Iterates from the end of the arrays to the beginning
    int i;
    for (i = len - 1; i >= 0; i--) {
        out[i] = in2[i] * window[i] + in1[i] * (1. - window[i]);
    }
}
