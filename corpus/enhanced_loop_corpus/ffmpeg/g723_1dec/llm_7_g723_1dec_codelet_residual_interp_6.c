#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int gain;
extern int *rseed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_rseed = *rseed;
    int16_t current_rseed;
    for (i = 0; i < (60 << 2); i += 2) {
        current_rseed = (int16_t)(prev_rseed * 521 + 259);
        out[i] = gain * current_rseed >> 15;
        prev_rseed = (int16_t)(current_rseed * 521 + 259);
        out[i + 1] = gain * prev_rseed >> 15;
    }
    *rseed = prev_rseed;
}
