#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Access elements with a stride of 2, processing even indices first, then odd if needed
    // Adjust loop bound to ensure we don't exceed array limits
    int stride = 2;
    int limit = ni - (ni % stride); // Round down to nearest multiple of stride

    for (i = 0; i < limit; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
        
        // Handle next element in stride (i+1) if within bounds
        if (i + 1 < ni) {
            left[i + 1] = ni - (i + 1) + 1;
            right[i + 1] = ((i + 1) <= h) ? ni : ni - ((i + 1) - h);
        }
    }

    // Cleanup any remaining element if ni is odd
    if (ni % 2 == 1) {
        i = ni - 1;
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
