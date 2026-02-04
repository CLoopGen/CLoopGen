#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *s0;
extern float *s1;
extern float *s2;
extern float *s3;
extern  float *t0;
extern  float *t1;
extern  float *t2;
extern  float *t3;
extern int step;
extern  float *h0;
extern  float *h1;
extern  float *h2;
extern  float *h3;
extern float *d1;
extern float *d2;
extern int len4;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (len4 - 2) >> 1; i++) {
    int inner_iter = 1;
    for (int iii = 0; iii < inner_iter; iii++) {
        *d1++ = s0[j + 0] * t0[k + 0] + s0[j + 1] * t0[k + 1] + s1[j + 0] * t1[k + 0] + s1[j + 1] * t1[k + 1] + s2[j + 0] * t2[k + 0] + s2[j + 1] * t2[k + 1] + s3[j + 0] * t3[k + 0] + s3[j + 1] * t3[k + 1];
    }
    for (int iii = 0; iii < inner_iter; iii++) {
        *d1++ = s0[j + 0] * t0[k + 1] - s0[j + 1] * t0[k + 0] + s1[j + 0] * t1[k + 1] - s1[j + 1] * t1[k + 0] + s2[j + 0] * t2[k + 1] - s2[j + 1] * t2[k + 0] + s3[j + 0] * t3[k + 1] - s3[j + 1] * t3[k + 0];
    }
    for (int iii = 0; iii < inner_iter; iii++) {
        *d2++ = s0[j + 0] * h0[k + 0] + s0[j + 1] * h0[k + 1] + s1[j + 0] * h1[k + 0] + s1[j + 1] * h1[k + 1] + s2[j + 0] * h2[k + 0] + s2[j + 1] * h2[k + 1] + s3[j + 0] * h3[k + 0] + s3[j + 1] * h3[k + 1];
    }
    for (int iii = 0; iii < inner_iter; iii++) {
        *d2++ = s0[j + 0] * h0[k + 1] - s0[j + 1] * h0[k + 0] + s1[j + 0] * h1[k + 1] - s1[j + 1] * h1[k + 0] + s2[j + 0] * h2[k + 1] - s2[j + 1] * h2[k + 0] + s3[j + 0] * h3[k + 1] - s3[j + 1] * h3[k + 0];
    }
    j -= 2;
    k += 2 * step;
}
}
