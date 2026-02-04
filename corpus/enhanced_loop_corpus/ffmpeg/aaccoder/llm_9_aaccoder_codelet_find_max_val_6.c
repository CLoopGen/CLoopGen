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
for (w2 = 0; w2 < (group_len + 1) / 2; w2++) {
    int base_index = w2 * 256;
    for (i = 0; i < swb_size; i++) {
        float val1 = scaled[base_index + i];
        float val2 = scaled[base_index + 128 + i];
        float local_max = (val1 > val2) ? val1 : val2;
        maxval = (maxval > local_max) ? maxval : local_max;
    }
}
}
