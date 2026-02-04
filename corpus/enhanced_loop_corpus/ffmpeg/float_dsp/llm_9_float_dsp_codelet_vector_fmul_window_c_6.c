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
    for (i = -len / 2, j = len - 1; i < 0; i++, j--) {
        float s0 = src0[i];
        float s1 = src1[j];
        float wi = win[i];
        float wj = win[j];
        float sum = s0 + s1;
        float diff = s0 - s1;
        float term1 = sum * (wi + wj);
        float term2 = diff * (wj - wi);
        
        dst[i] = (term1 - term2) * 0.5f;
        dst[j] = (term1 + term2) * 0.5f;
    }
}
