#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    FFTSample *out = output;
    FFTSample *out_mid = output + n2;
    FFTSample *out_end = output + n;
    for (int i = 0; i < n4; i++) {
        out[i] = -out_mid[-i - 1];
        out_end[-i - 1] = out_mid[i];
    }
}
