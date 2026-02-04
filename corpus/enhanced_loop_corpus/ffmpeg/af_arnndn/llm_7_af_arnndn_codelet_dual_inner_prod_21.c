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
    float temp1 = xy01;
    float temp2 = xy02;
    for (int i = 0; i < N; i++) {
        temp1 = temp1 + (x[i] * y01[i]);
        temp2 = temp2 + (x[i] * y02[i]);
    }
    xy01 = temp1;
    xy02 = temp2;
}
