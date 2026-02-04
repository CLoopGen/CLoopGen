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
    float temp_xy01 = 0.0f;
    float temp_xy02 = 0.0f;
    for (int i = 0; i < N; i++) {
        temp_xy01 += (x[i] * y01[i]);
        temp_xy02 += (x[i] * y02[i]);
    }
    xy01 += temp_xy01;
    xy02 += temp_xy02;
}
