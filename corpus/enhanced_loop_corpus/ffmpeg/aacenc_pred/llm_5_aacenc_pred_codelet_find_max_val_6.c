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
    int first = 1;
    for (w2 = 0; w2 < group_len && !first; w2++) {
        for (i = 0; i < swb_size; i++) {
            if (first || scaled[w2 * 128 + i] > maxval) {
                maxval = scaled[w2 * 128 + i];
                first = 0;
            }
        }
    }
    if (first && group_len > 0 && swb_size > 0) {
        maxval = scaled[0];
    }
}
