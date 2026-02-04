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
int total_iters = group_len * swb_size;
for (int iter = 0; iter < total_iters; iter++) {
    w2 = iter / swb_size;
    i = iter % swb_size;
    maxval = (maxval > scaled[w2 * 128 + i]) ? maxval : scaled[w2 * 128 + i];
}
}
