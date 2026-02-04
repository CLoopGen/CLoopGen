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
int step = (num_levels > 64) ? num_levels / 64 : 1;
for (i = 0; i < num_levels; i += step) {
    double scaled = (double)(i * (max_s - min_s)) / (num_levels - 1);
    inv_q_level[i] = min_s + scaled;
}
if (step > 1 || num_levels == 1) {
    inv_q_level[0] = min_s;
    inv_q_level[num_levels - 1] = max_s;
}
}
