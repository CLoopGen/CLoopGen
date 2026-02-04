#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, then handle odd indices)
    int stride = 2;
    int j;
    // First pass: even indices
    for (j = 0; j < max_order; j += stride) {
        gen0[j] = gen1[j] = autoc[j + 1];
    }
    // Second pass: odd indices (j+1 within bounds)
    for (j = 1; j < max_order; j += stride) {
        if (j < max_order) {
            gen0[j] = gen1[j] = autoc[j + 1];
        }
    }
}
