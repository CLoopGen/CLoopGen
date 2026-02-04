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
    // Variant 1: Strided memory access with step size 2, unrolled to handle pairs
    int stride = 2;
    int limit = ni - (ni % stride); // Make sure we don't go out of bounds
    for (i = 0; i < limit; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
        if (i + 1 < ni) {
            left[i + 1] = ni - (i + 1) + 1;
            right[i + 1] = ((i + 1) <= h) ? ni : ni - ((i + 1) - h);
        }
    }
    // Handle any remaining element if ni is odd
    if (limit < ni) {
        i = ni - 1;
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
