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
    int first_update = 1;
    for (w2 = 0; w2 < group_len; w2++) {
        for (i = 0; i < swb_size; i++) {
            float val = scaled[w2 * 128 + i];
            if (first_update || val > maxval) {
                maxval = val;
                first_update = 0;
            }
        }
    }
}
