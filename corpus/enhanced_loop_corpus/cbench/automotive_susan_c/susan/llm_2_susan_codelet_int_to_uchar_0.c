#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // This variant processes every second element in the first pass,
    // then handles the remaining elements in a second sequential pass.
    int stride = 2;
    // First pass: even indices
    for (i = 0; i < size; i += stride) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
    }
    // Second pass: odd indices (strided pattern completion)
    for (i = 1; i < size; i += stride) {
        if (r[i] > max_r)
            max_r = r[i];
        if (r[i] < min_r)
            min_r = r[i];
    }
}
