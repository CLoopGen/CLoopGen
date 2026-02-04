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
for (w2 = 0; w2 < group_len; w2 += 2) {
    for (i = 0; i < swb_size; i++) {
        float val1 = scaled[w2 * 128 + i];
        maxval = (maxval > val1) ? maxval : val1;
        if (w2 + 1 < group_len) {
            float val2 = scaled[(w2 + 1) * 128 + i];
            maxval = (maxval > val2) ? maxval : val2;
        }
    }
}
}
