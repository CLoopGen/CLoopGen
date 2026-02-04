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
        float xd0 = x[i] - xm;
        float yd0 = y[i] - ym;
        num += xd0 * yd0;
        den0 += xd0 * xd0;
        den1 += yd0 * yd0;

        if (i + 1 < size) {
            float xd1 = x[i + 1] - xm;
            float yd1 = y[i + 1] - ym;
            num += xd1 * yd1;
            den0 += xd1 * xd1;
            den1 += yd1 * yd1;
        }
    }
}
