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
for (w2 = 0; w2 < group_len && w2 < 64; w2++) {
    int idx = w2 * 128;
    float local_max = scaled[idx];
    for (i = 1; i < swb_size && i < 32; i++) {
        local_max = (local_max > scaled[idx + i]) ? local_max : scaled[idx + i];
    }
    maxval = (maxval > local_max) ? maxval : local_max;
}
}
