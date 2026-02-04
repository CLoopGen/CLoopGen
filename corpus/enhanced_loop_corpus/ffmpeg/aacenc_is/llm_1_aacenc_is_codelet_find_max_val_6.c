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
for (i = 0; i < total; i++) {
    float val = scaled[i];
    if (val > maxval) {
        maxval = val;
    }
}
}
