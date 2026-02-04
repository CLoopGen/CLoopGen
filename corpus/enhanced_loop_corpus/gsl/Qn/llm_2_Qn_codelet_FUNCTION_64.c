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
    // Variant 1: Strided memory access with step size 2
    // Arrays are accessed in a strided pattern: i += 2, processing even indices only.
    // Remaining elements (odd indices) are handled in a second forward pass with offset.
    int stride = 2;
    for (i = 0; i < ni; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
    for (i = 1; i < ni; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
