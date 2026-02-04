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
    int temp_gain = gain;
    int16_t local_rseed = *rseed;
    for (i = 0; i < (60 << 2); i++) {
        local_rseed = (int16_t)(local_rseed * 521 + 259);
        out[i] = temp_gain * local_rseed >> 15;
    }
    *rseed = local_rseed;
}
