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
int prev_temp = 0;
for (x = 0; x < w2; x++) {
    int current_tmp_val = (int)(tmp[x] + 1U);
    int shifted_val = current_tmp_val >> 1;
    b[2 * x] = (x == 0) ? shifted_val : prev_temp;
    prev_temp = shifted_val;

    if (x > 0 && x + 1 < w2) {
        int mixed_input = (int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8);
        int filtered = (((unsigned int)(b[x + w2]) + (mixed_input >> 4)) + 1U) >> 1;
        b[2 * x + 1] = filtered;
    } else {
        b[2 * x + 1] = shifted_val;
    }
}
}
