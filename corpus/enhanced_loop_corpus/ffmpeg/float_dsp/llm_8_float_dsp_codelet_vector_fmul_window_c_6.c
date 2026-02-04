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
    for (i = -len + 2; i < 0; i += 2, j -= 2) {
        float s0_i = src0[i];
        float s1_j = src1[j];
        float wi_i = win[i];
        float wj_j = win[j];
        
        float s0_ip1 = src0[i + 1];
        float s1_jm1 = src1[j - 1];
        float wi_ip1 = win[i + 1];
        float wj_jm1 = win[j - 1];

        dst[i]     = s0_i * wj_j - s1_j * wi_i;
        dst[j]     = s0_i * wi_i + s1_j * wj_j;
        dst[i + 1] = s0_ip1 * wj_jm1 - s1_jm1 * wi_ip1;
        dst[j - 1] = s0_ip1 * wi_ip1 + s1_jm1 * wj_jm1;
    }
}
