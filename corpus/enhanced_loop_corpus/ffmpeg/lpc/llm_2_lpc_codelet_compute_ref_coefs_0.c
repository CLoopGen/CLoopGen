#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double LPC_TYPE;

extern  LPC_TYPE *autoc;
extern int max_order;
extern int i;
extern LPC_TYPE gen0[32];
extern LPC_TYPE gen1[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling by 2
    int limit = max_order - (max_order % 2);
    for (i = 0; i < limit; i += 2) {
        gen0[i]     = autoc[i + 1];
        gen1[i]     = autoc[i + 1];
        gen0[i + 1] = autoc[i + 2];
        gen1[i + 1] = autoc[i + 2];
    }
    // Handle remaining element if max_order is odd
    if (i < max_order) {
        gen0[i] = gen1[i] = autoc[i + 1];
    }
}
