#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **h;
extern int *len;
extern float phase;
extern float *work;
extern int i;
extern int work_len;
extern int begin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float scale = phase * 0.1F;
for (i = 0; i < *len; i++) {
    int offset = (phase > 50.F ? *len - 1 - i : i);
    int wrapped_index = (begin + offset + work_len) & (work_len - 1);
    float val = work[wrapped_index] * scale;
    (*h)[i] = val + ((val > 10.0F) ? -1.5F : 1.5F);
}
}
