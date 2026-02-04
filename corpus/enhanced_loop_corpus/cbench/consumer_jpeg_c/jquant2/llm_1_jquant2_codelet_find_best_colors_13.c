#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern int i;
extern INT32 *bptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    int inner_i;
    int total_iters = (1 << (5 - 3)) * (1 << (6 - 3)) * (1 << (5 - 3));
    int sqrt_iters = 1 << (5 - 3); // Approximate square root of total_iters (8x8x8 = 512, sqrt ~22.6, but we use 8 for clean nesting)
    
    for (outer_i = sqrt_iters - 1; outer_i >= 0; outer_i--)
        for (inner_i = sqrt_iters - 1; inner_i >= 0; inner_i--) {
            *bptr++ = 2147483647L;
            if (--total_iters <= 0) break;
        }
}
