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
    // Access elements with a stride of 2, processing even indices first, then odd if needed.
    // To maintain correctness, we assume ni is even for simplicity, or handle remainder safely.
    int stride = 2;
    int i;
    // First pass: even indices
    for (i = 0; i < ni; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
    // Second pass: odd indices (strided access covering all elements)
    for (i = 1; i < ni; i += stride) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
