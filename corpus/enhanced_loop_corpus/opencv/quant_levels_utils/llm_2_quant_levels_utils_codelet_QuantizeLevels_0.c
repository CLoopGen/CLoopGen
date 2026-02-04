#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_levels;
extern double inv_q_level[256];
extern int min_s;
extern int max_s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, processing even indices first
    int stride = 2;
    int i;
    for (i = 0; i < num_levels; i += stride) {
        inv_q_level[i] = min_s + (double)(max_s - min_s) * i / (num_levels - 1);
    }
    // Handle odd index if num_levels is odd
    for (i = 1; i < num_levels; i += stride) {
        inv_q_level[i] = min_s + (double)(max_s - min_s) * i / (num_levels - 1);
    }
}
