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
    // Variant 1: Strided memory access with step size 2 (unrolled-like pattern)
    // Process elements in strides of 2 for both left and right arrays
    int stride = 2;
    int limit = ni - (ni % stride); // Make sure we don't overflow

    for (i = 0; i < limit; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);

        // Handle next element in stride if within bounds
        if (i + 1 < ni) {
            left[i + 1] = ni - (i + 1) + 1;
            right[i + 1] = ((i + 1) <= h) ? ni : ni - ((i + 1) - h);
        }
    }

    // Handle any remaining element if ni is odd
    if (ni % stride && limit < ni) {
        left[ni - 1] = ni - (ni - 1) + 1;
        right[ni - 1] = ((ni - 1) <= h) ? ni : ni - ((ni - 1) - h);
    }
}
