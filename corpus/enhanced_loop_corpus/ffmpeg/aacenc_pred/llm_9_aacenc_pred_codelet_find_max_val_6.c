#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int group_len;
extern int swb_size;
extern  float *scaled;
extern float maxval;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (w2 = 0; w2 < group_len; w2++) {
    int base_index = w2 * 128;
    float local_max = -__FLT_MAX__;
    for (i = 0; i < swb_size; i++) {
        local_max = (local_max > scaled[base_index + i]) ? local_max : scaled[base_index + i];
    }
    maxval = (maxval > local_max) ? maxval : local_max;
}
}
