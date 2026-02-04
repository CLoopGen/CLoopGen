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



void loop() {
    float temp_max = 0.0f;
    for (w2 = 0; w2 < group_len; w2++) {
        float local_max = 0.0f;
        for (i = 0; i < swb_size; i++) {
            float val = scaled[w2 * 128 + i];
            local_max = (local_max > val) ? local_max : val;
        }
        temp_max = (temp_max > local_max) ? temp_max : local_max;
    }
    maxval = temp_max;
}
