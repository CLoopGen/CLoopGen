#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y01;
extern  float *y02;
extern int N;
extern float xy01;
extern float xy02;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < N * 2; i++) {
        int idx = i / 2;
        xy01 += (x[idx] * y01[idx]);
        xy02 += (x[idx] * y02[idx]);
    }
}
