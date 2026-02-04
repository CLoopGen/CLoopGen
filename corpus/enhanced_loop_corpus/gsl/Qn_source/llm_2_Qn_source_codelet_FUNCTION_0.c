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
    // Processes elements at even indices first, then odd if needed, but here we assume ni is even for simplicity
    int stride = 2;
    int i;
    for (i = 0; i < ni; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
        if (i + 1 < ni) {
            left[i + 1] = ni - (i + 1) + 1;
            right[i + 1] = ((i + 1) <= h) ? ni : ni - ((i + 1) - h);
        }
    }
}
