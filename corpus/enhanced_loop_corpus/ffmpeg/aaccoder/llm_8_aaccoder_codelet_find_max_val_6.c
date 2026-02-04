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
for (w2 = 0; w2 < group_len * 2; w2++) {
    for (i = 0; i < swb_size; i += 2) {
        if (w2 * 128 + i < group_len * 128 && (w2 * 128 + i) % 128 < swb_size) {
            maxval = ((maxval) > (scaled[w2 * 128 + i]) ? (maxval) : (scaled[w2 * 128 + i]));
        }
        if (i + 1 < swb_size && w2 * 128 + i + 1 < group_len * 128) {
            maxval = ((maxval) > (scaled[w2 * 128 + i + 1]) ? (maxval) : (scaled[w2 * 128 + i + 1]));
        }
    }
}
}
