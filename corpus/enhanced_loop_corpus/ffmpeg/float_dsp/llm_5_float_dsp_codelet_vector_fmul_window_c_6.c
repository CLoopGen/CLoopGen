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
    for (i = -len, j = len - 1; i < 0; i++, j--) {
        float wi = win[i];
        float wj = win[j];
        if (wi > 0.5f && wj > 0.5f) {
            float s0 = src0[i];
            float s1 = src1[j];
            dst[i] = s0 * wj - s1 * wi;
            dst[j] = s0 * wi + s1 * wj;
        } else {
            float avg = (win[i] + win[j]) * 0.5f;
            dst[i] = (src0[i] + src1[j]) * avg;
            dst[j] = (src1[j] + src0[i]) * avg;
        }
    }
}
