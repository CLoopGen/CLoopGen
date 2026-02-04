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
    int use_reverse = phase > 50.F;
    for (i = 0; i < *len; i++) {
        int offset = use_reverse ? *len - 1 - i : i;
        int idx = (begin + offset + work_len) & (work_len - 1);
        (*h)[i] = work[idx];
        if ((*h)[i] == 0.F) continue;
    }
}
