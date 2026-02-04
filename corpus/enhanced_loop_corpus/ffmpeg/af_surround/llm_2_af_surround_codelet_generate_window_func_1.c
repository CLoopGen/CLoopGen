#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    int pass;
    for (pass = 0; pass < stride; pass++) {
        for (n = pass; n < N; n += stride) {
            float center = (N - 1) / 2.0f;
            float norm = (n - center) / center;
            lut[n] = 1.0f - norm * norm;
        }
    }
}
