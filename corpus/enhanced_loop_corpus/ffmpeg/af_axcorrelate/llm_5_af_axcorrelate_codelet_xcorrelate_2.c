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
    float xd, yd;
    for (int i = 0; i < size; i++) {
        xd = x[i] - xm;
        yd = y[i] - ym;
        num += xd * yd;
        if (i % 2 == 0) {
            den0 += xd * xd;
        } else {
            den1 += yd * yd;
        }
    }
}
