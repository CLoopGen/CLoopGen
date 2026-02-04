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
    // Variant 1: Strided memory access with step size of 2
    // This variant accesses every second element in a forward pass, then a backward pass for remaining elements
    int stride = 2;
    int i;
    for (i = 0; i < ni; i += stride) {
        if (i < ni) {
            left[i] = ni - i + 1;
            right[i] = (i <= h) ? ni : ni - (i - h);
        }
        int j = i + 1;
        if (j < ni) {
            left[j] = ni - j + 1;
            right[j] = (j <= h) ? ni : ni - (j - h);
        }
    }
}
