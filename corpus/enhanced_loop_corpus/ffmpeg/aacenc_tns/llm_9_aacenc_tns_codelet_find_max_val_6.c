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
int stride = 64;
for (w2 = 0; w2 < group_len; w2++) {
    for (i = 0; i < swb_size; i++) {
        for (int j = 0; j < 128; j += stride) {
            int idx = w2 * 128 + i + j;
            if (i + j < 128) {
                maxval = (maxval > scaled[idx]) ? maxval : scaled[idx];
            }
        }
    }
}
}
