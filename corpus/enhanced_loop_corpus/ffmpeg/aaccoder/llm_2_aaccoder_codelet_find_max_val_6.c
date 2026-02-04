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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing scaled in row-major order (w2 * 128 + i), 
    // we reverse the access pattern to stride through memory with step size 128,
    // effectively traversing one column at a time across groups.
    for (i = 0; i < swb_size; i++) {
        for (w2 = 0; w2 < group_len; w2++) {
            float val = scaled[i + w2 * 128]; // Strided access: step by 128
            maxval = (maxval > val) ? maxval : val;
        }
    }
}
