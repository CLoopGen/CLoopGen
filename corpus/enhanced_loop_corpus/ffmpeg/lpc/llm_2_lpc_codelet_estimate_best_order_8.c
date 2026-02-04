#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *ref;
extern int min_order;
extern int max_order;
extern int i;
extern int est;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), traversing backwards with reduced iteration frequency
    int stride = 2;
    int start = (max_order - 1) % stride == 0 ? max_order - 1 : max_order - 1 - ((max_order - 1) % stride);
    for (i = start; i >= min_order - 1; i -= stride) {
        if (ref[i] > 0.10000000000000001) {
            est = i + 1;
            break;
        }
    }
    // Fallback linear scan from original start down to ensure correctness if strided missed valid index
    if (est == 0) {
        for (i = max_order - 1; i >= min_order - 1; i--) {
            if (ref[i] > 0.10000000000000001) {
                est = i + 1;
                break;
            }
        }
    }
}
