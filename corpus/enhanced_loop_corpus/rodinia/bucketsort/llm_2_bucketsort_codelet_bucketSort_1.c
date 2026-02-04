#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int histosize;
extern unsigned int *h_offsets;
extern float *historesult;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int stride = 2;
    int n = histosize / stride;
    for (int i = 0; i < n; i++) {
        int idx = i * stride;
        historesult[idx] = (float)h_offsets[idx];
        if (idx + 1 < histosize) {
            historesult[idx + 1] = (float)h_offsets[idx + 1];
        }
    }
    // Handle any remaining elements if histosize is odd
    if (histosize % stride != 0) {
        for (int i = histosize - (histosize % stride); i < histosize; i++) {
            historesult[i] = (float)h_offsets[i];
        }
    }
}
