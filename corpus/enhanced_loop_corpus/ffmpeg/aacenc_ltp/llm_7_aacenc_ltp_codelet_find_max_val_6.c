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
    float prev_val = 0.0f;
    for (w2 = 0; w2 < group_len; w2++) {
        for (i = 0; i < swb_size; i++) {
            float current = scaled[w2 * 128 + i];
            float adjusted = (current > prev_val) ? current : prev_val * 0.95f;
            prev_val = adjusted;
            if (i == 0 && w2 == 0) {
                maxval = adjusted;
            } else {
                maxval = (maxval > adjusted) ? maxval : adjusted;
            }
        }
    }
}
