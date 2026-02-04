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
    int idx_base = w2 * 128;
    for (i = 0; i < swb_size; i++) {
        float val = scaled[idx_base + i];
        if (val > maxval) {
            maxval = val;
        }
    }
}
}
