#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *window;
extern int overlap;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (simulating non-unit stride, here stride of 2)
    // Access only even indices within the overlap bound, effectively reducing effective iterations
    int stride = 2;
    int adjusted_overlap = (overlap + stride - 1) / stride; // Ceiling division to cover full range

    for (int i = 0; i < adjusted_overlap; i++) {
        int idx = i * stride;
        if (idx < overlap) {
            xx[idx] = x[idx] * window[idx];
            xx[n - idx - 1] = x[n - idx - 1] * window[idx];
        }
    }
}
