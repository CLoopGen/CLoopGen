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
    if (num_levels <= 0) return;
    for (i = 0; i < num_levels; ++i) {
        if (i == 0) {
            inv_q_level[i] = min_s;
        } else if (i == num_levels - 1) {
            inv_q_level[i] = max_s;
        } else {
            inv_q_level[i] = min_s + (double)(max_s - min_s) * i / (num_levels - 1);
        }
    }
}
