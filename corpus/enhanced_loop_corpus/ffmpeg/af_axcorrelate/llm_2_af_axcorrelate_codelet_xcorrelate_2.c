#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int size;
extern  float xm;
extern  float ym;
extern float num;
extern float den0;
extern float den1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < size; i += 2) {
        float xd = x[i] - xm;
        float yd = y[i] - ym;
        num += xd * yd;
        den0 += xd * xd;
        den1 += yd * yd;
    }
}
