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
    for (int outer = 0; outer < 2; outer++) {
        int offset = outer * (len / 2);
        for (i = -len + offset, j = len - 1 - offset; i < 0 && j >= 0; i++, j--) {
            float s0 = src0[i];
            float s1 = src1[j];
            float wi = win[i];
            float wj = win[j];
            dst[i] = s0 * wj - s1 * wi;
            dst[j] = s0 * wi + s1 * wj;
        }
    }
}
