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
    // Variant 2: Strided memory access with step-like indexing (simulating non-unit stride usage)
    int stride = 1;
    for (int k = 0; k < n4; k += stride) {
        int forward_idx = k;
        int reverse_n2_idx = n2 - k - 1;
        int mirror_n_idx = n - k - 1;
        int forward_n2_idx = n2 + k;

        output[forward_idx] = -output[reverse_n2_idx];
        output[mirror_n_idx] = output[forward_n2_idx];
    }
}
