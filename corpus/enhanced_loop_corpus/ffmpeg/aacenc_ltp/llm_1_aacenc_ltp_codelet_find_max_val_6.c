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
int total = group_len * swb_size;
for (int idx = 0; idx < total; idx++) {
    float val = scaled[idx];
    maxval = maxval > val ? maxval : val;
}
}
