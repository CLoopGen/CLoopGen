#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential access, access every 4th element in a strided manner
    int stride = 4;
    int total_elements = w * h;
    for (i = 0; i < total_elements; i += stride) {
        if (i < total_elements) {
            t[i] *= 1 << 8;
        }
        // Process remaining elements within the stride if needed
        int j = i + 1;
        if (j < total_elements) {
            t[j] *= 1 << 8;
        }
        j = i + 2;
        if (j < total_elements) {
            t[j] *= 1 << 8;
        }
        j = i + 3;
        if (j < total_elements) {
            t[j] *= 1 << 8;
        }
    }
}
