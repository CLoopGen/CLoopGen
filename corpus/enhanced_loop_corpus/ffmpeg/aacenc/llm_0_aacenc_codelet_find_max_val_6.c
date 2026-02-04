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
    maxval = ((maxval) > (scaled[w2 * 128]) ? (maxval) : (scaled[w2 * 128]));
    for (i = 1; i < swb_size; i++) {
        maxval = ((maxval) > (scaled[w2 * 128 + i]) ? (maxval) : (scaled[w2 * 128 + i]));
    }
}
}
