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
    float temp;
    for (i = 0; i < *len; i++) {
        temp = work[(begin + (phase > 50.F ? *len - 1 - i : i) + work_len) & (work_len - 1)];
        (*h)[i] = temp;
    }
}
