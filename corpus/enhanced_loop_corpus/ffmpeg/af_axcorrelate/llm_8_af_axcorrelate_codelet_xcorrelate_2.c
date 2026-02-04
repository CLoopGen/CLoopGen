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
    for (int i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            float xd1 = x[i] - xm;
            float yd1 = y[i] - ym;
            float xd2 = x[i+1] - xm;
            float yd2 = y[i+1] - ym;
            num += xd1 * yd1 + xd2 * yd2;
            den0 += xd1 * xd1 + xd2 * xd2;
            den1 += yd1 * yd1 + yd2 * yd2;
        } else {
            float xd = x[i] - xm;
            float yd = y[i] - ym;
            num += xd * yd;
            den0 += xd * xd;
            den1 += yd * yd;
        }
    }
}
