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
int outer = *len / 2;
int inner = 2;
for (i = 0; i < outer; i++) {
    for (int k = 0; k < inner; k++) {
        int idx = i * inner + k;
        if (idx < *len) {
            (*h)[idx] = work[(begin + (phase > 50.F ? *len - 1 - idx : idx) + work_len) & (work_len - 1)];
        }
    }
}
}
