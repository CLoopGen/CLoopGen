#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of sequential access, access elements with a stride of 2
    // This changes the memory access pattern to non-consecutive but still predictable
    int stride = 2;
    for (k = 0; k < n4; k += stride) {
        // Ensure we don't exceed bounds when applying stride
        if (k < n4) {
            output[k] = -output[n2 - k - 1];
            output[n - k - 1] = output[n2 + k];
        }
        int k_next = k + 1;
        if (k_next < n4) {
            output[k_next] = -output[n2 - k_next - 1];
            output[n - k_next - 1] = output[n2 + k_next];
        }
    }
}
