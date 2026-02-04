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
    // Variant 2: Reverse consecutive memory access pattern
    int i;
    for (i = num_levels - 1; i >= 0; --i) {
        inv_q_level[i] = min_s + (double)(max_s - min_s) * i / (num_levels - 1);
    }
}
