#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_b_val = 0;
for (x = 0; x < w2; x++) {
    int adjusted_tmp = (int)(tmp[x] + 1U);
    b[2 * x] = adjusted_tmp >> 1;

    int input_sum = 9U * tmp[x] + (x + 1 < w2 ? 9U * tmp[x + 1] : 0) - (x + 2 < w2 ? tmp[x + 2] : 0) - (x - 1 >= 0 ? tmp[x - 1] : 0);
    int shifted_input = (input_sum + 8) >> 4;
    int combined = ((int)((unsigned int)(prev_b_val + shifted_input)) + 1U) >> 1;
    b[2 * x + 1] = combined;

    prev_b_val = b[x + w2];
}
}
