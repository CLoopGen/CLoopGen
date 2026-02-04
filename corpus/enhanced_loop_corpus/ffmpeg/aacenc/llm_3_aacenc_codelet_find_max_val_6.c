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
int idx;
for (idx = 0; idx < group_len * swb_size; idx++) {
    int w2 = idx / swb_size;
    int i = idx % swb_size;
    maxval = ((maxval) > (scaled[w2 * 128 + i]) ? (maxval) : (scaled[w2 * 128 + i]));
}
}
