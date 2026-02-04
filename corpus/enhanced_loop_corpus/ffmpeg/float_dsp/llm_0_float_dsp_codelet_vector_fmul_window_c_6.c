#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern  float *win;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 1; k++) {
        for (i = -len, j = len - 1; i < 0; i++, j--) {
            float s0 = src0[i];
            float s1 = src1[j];
            float wi = win[i];
            float wj = win[j];
            dst[i] = s0 * wj - s1 * wi;
            dst[j] = s0 * wi + s1 * wj;
        }
    }
}
