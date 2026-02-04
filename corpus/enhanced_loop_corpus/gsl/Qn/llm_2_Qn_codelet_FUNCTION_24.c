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
    // Arrays are accessed in strides of 2, processing even indices first.
    // Remaining elements (odd indices) are handled in a second forward pass.
    
    int stride = 2;
    int j;
    for (j = 0; j < ni; j += stride) {
        left[j] = ni - j + 1;
        right[j] = (j <= h) ? ni : ni - (j - h);
    }
    // Handle any remaining element if ni is odd
    if (ni % 2 == 1) {
        for (j = 1; j < ni; j += stride) {
            left[j] = ni - j + 1;
            right[j] = (j <= h) ? ni : ni - (j - h);
        }
    }
}
