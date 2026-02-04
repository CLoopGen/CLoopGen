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
    for (i = 0; i < *len; i++) {
        int index = (begin + i + work_len) & (work_len - 1);
        (*h)[i] = work[index];
        if (i > 0) {
            (*h)[i] += (*h)[i - 1] * 0.1f; 
        }
    }
}
