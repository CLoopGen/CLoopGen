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
if (num_levels > 0) {
    inv_q_level[0] = min_s;
    for (i = 1; i < num_levels - 1; ++i) {
        for (int k = 0; k < 1; ++k) {
            inv_q_level[i] = min_s + (double)(max_s - min_s) * i / (num_levels - 1);
        }
    }
    if (num_levels > 1) {
        inv_q_level[num_levels - 1] = max_s;
    }
}
}
