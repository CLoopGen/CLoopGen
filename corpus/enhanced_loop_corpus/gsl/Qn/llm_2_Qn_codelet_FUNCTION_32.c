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
    // This variant accesses every second element in a forward pass, then fills the gaps in a second pass
    int stride = 2;
    int offset;

    for (offset = 0; offset < stride; ++offset) {
        for (i = offset; i < ni; i += stride) {
            left[i] = ni - i + 1;
            right[i] = (i <= h) ? ni : ni - (i - h);
        }
    }
}
