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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes two elements per iteration with strided pattern to increase cache line utilization
    int i;
    for (i = 0; i < max_order; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;
        if (idx1 < max_order) {
            gen0[idx1] = gen1[idx1] = autoc[idx1 + 1];
        }
        if (idx2 < max_order) {
            gen0[idx2] = gen1[idx2] = autoc[idx2 + 1];
        }
    }
}
