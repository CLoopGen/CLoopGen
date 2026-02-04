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
    maxval = scaled[0]; // Initialize with first element to avoid undefined behavior
    for (w2 = 0; w2 < group_len; w2++) {
        float prev_val = (w2 > 0) ? scaled[(w2 - 1) * 128] : scaled[0];
        for (i = 0; i < swb_size; i++) {
            int idx = w2 * 128 + i;
            float current = scaled[idx];
            // Introduce artificial loop-carried dependency: mix with previous block's first value
            float adjusted = (i == 0) ? ((prev_val + current) * 0.5f) : current;
            maxval = (maxval > adjusted) ? maxval : adjusted;
        }
    }
}
