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
        int index = (begin + (*len - 1 - i) + work_len) & (work_len - 1);
        if (phase <= 50.F) {
            index = (begin + i + work_len) & (work_len - 1);
        }
        (*h)[i] = work[index];
    }
}
