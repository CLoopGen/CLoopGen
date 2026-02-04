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
    // Instead of accessing scaled in row-major order (w2 * 128 + i), we reverse the indexing
    // to access memory with a stride of 1 across w2 for each fixed i, promoting spatial locality in i
    for (i = 0; i < swb_size; i++) {
        for (w2 = 0; w2 < group_len; w2++) {
            float val = scaled[w2 * 128 + i];
            maxval = (maxval > val) ? maxval : val;
        }
    }
}
