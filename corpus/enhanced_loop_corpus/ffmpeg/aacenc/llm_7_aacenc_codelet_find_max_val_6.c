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
    float temp_max = -__FLT_MAX__;
    for (w2 = 0; w2 < group_len; w2++) {
        float row_max = scaled[w2 * 128];
        for (i = 1; i < swb_size; i++) {
            row_max = (row_max > scaled[w2 * 128 + i]) ? row_max : scaled[w2 * 128 + i];
        }
        temp_max = (temp_max > row_max) ? temp_max : row_max;
    }
    maxval = (maxval > temp_max) ? maxval : temp_max;
}
