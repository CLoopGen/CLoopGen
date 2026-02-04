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
    // Variant 1: Strided Memory Access (stride of 2, then handle odd/even indices)
    int stride = 2;
    int j;
    // First pass: even indices
    for (j = 0; j < (max_order + 1) / 2; j++) {
        int idx = j * stride;
        if (idx < max_order) {
            gen0[idx] = gen1[idx] = autoc[idx + 1];
        }
    }
    // Second pass: odd indices (simulate strided access starting at 1)
    for (j = 0; j < max_order / 2; j++) {
        int idx = j * stride + 1;
        if (idx < max_order) {
            gen0[idx] = gen1[idx] = autoc[idx + 1];
        }
    }
}
