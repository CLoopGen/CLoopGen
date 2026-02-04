#include <stdio.h>

#include <inttypes.h>

typedef char base;

extern int n;
extern base seq[2500];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // We traverse the array with a step size of 2, alternating two separate sequences
    // Values are still assigned as (i+1) % 4 but only on even indices first, then odd
    int stride = 2;
    for (i = 0; i < n; i += stride) {
        seq[i] = (base)((i + 1) % 4);
    }
    for (i = 1; i < n; i += stride) {
        seq[i] = (base)((i + 1) % 4);
    }
}
