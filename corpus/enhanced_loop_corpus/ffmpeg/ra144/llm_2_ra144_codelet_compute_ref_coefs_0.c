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
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // Processes two elements per iteration in a strided pattern for improved cache behavior
    int i;
    for (i = 0; i < max_order; i += 2) {
        if (i + 1 < max_order) {
            gen0[i]     = autoc[i + 1];
            gen1[i]     = autoc[i + 1];
            gen0[i + 1] = autoc[i + 2];
            gen1[i + 1] = autoc[i + 2];
        } else {
            gen0[i] = gen1[i] = autoc[i + 1];
        }
    }
}
