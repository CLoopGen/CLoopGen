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
    float temp_scaled[128] = {0};
    for (w2 = 0; w2 < group_len; w2++) {
        for (i = 0; i < swb_size; i++) {
            temp_scaled[i] = scaled[w2 * 128 + i];
        }
        for (i = 0; i < swb_size; i++) {
            maxval = (maxval > temp_scaled[i]) ? maxval : temp_scaled[i];
        }
    }
}
