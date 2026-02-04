#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *data;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Original strided access (i += 2) changed to consecutive (i++) with adjusted indexing
    // This variant processes two elements per iteration in a sequential manner
    for (i = 1; i < n - 2; i++) {
        if ((i % 2) == 1) {  // Only process odd indices to match original logic
            data[i + 1] += data[i - 1];
            data[i] = -data[i + 2];
        }
    }
}
