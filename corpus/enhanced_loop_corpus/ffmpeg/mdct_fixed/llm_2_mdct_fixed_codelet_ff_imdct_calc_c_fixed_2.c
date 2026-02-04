#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    FFTSample *out = output;
    FFTSample *out_n2 = output + n2;
    FFTSample *out_n = output + n;
    FFTSample *out_n2_end = output + n2 - 1;

    for (int idx = 0; idx < n4; idx++) {
        out[idx] = -out_n2_end[-idx];
        out_n[-idx - 1] = out_n2[idx];
    }
}
