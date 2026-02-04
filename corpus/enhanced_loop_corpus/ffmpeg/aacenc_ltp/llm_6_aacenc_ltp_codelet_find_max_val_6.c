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
    float local_max = maxval;
    for (w2 = 0; w2 < group_len; w2++) {
        float temp_max = scaled[w2 * 128];
        for (i = 1; i < swb_size; i++) {
            temp_max = (temp_max > scaled[w2 * 128 + i]) ? temp_max : scaled[w2 * 128 + i];
        }
        local_max = (local_max > temp_max) ? local_max : temp_max;
    }
    maxval = local_max;
}
