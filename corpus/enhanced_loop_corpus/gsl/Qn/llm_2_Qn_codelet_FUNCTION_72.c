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
    // Instead of accessing consecutive elements, we step through the array with a stride of 2
    // Elements are updated in two passes: first even indices, then odd indices to cover all
    int stride = 2;
    int start;

    for (start = 0; start < stride; ++start) {
        for (i = start; i < ni; i += stride) {
            left[i] = ni - i + 1;
            right[i] = (i <= h) ? ni : ni - (i - h);
        }
    }
}
