#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int16_t *b;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 1; x < w2 - 1; x++) {
    int t0 = tmp[x];
    int t1 = tmp[x + 1];
    int t_1 = tmp[x - 1];
    int t2 = tmp[x + 2];
    int weighted_sum = (11U * t0 + 11U * t1 - 3U * t2 - 3U * t_1 + 16) >> 5;
    int corrected_val = ((int)(((unsigned int)(b[x + w2]) + weighted_sum) + 1U)) >> 1;
    b[2 * x] = ((int)(t0 + 1U)) >> 1;
    b[2 * x + 1] = corrected_val;
}
}
