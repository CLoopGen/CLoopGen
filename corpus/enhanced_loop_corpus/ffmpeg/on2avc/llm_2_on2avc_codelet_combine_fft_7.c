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
    int idx_s = j;
    int idx_tk0 = k;
    int idx_tk1 = k + step;
    int idx_hk0 = k;
    int idx_hk1 = k + step;

    *d1++ = s0[idx_s] * t0[idx_tk0] + s0[idx_s + 1] * t0[idx_tk1] +
            s1[idx_s] * t1[idx_tk0] + s1[idx_s + 1] * t1[idx_tk1] +
            s2[idx_s] * t2[idx_tk0] + s2[idx_s + 1] * t2[idx_tk1] +
            s3[idx_s] * t3[idx_tk0] + s3[idx_s + 1] * t3[idx_tk1];

    *d1++ = s0[idx_s] * t0[idx_tk1] - s0[idx_s + 1] * t0[idx_tk0] +
            s1[idx_s] * t1[idx_tk1] - s1[idx_s + 1] * t1[idx_tk0] +
            s2[idx_s] * t2[idx_tk1] - s2[idx_s + 1] * t2[idx_tk0] +
            s3[idx_s] * t3[idx_tk1] - s3[idx_s + 1] * t3[idx_tk0];

    *d2++ = s0[idx_s] * h0[idx_hk0] + s0[idx_s + 1] * h0[idx_hk1] +
            s1[idx_s] * h1[idx_hk0] + s1[idx_s + 1] * h1[idx_hk1] +
            s2[idx_s] * h2[idx_hk0] + s2[idx_s + 1] * h2[idx_hk1] +
            s3[idx_s] * h3[idx_hk0] + s3[idx_s + 1] * h3[idx_hk1];

    *d2++ = s0[idx_s] * h0[idx_hk1] - s0[idx_s + 1] * h0[idx_hk0] +
            s1[idx_s] * h1[idx_hk1] - s1[idx_s + 1] * h1[idx_hk0] +
            s2[idx_s] * h2[idx_hk1] - s2[idx_s + 1] * h2[idx_hk0] +
            s3[idx_s] * h3[idx_hk1] - s3[idx_s + 1] * h3[idx_hk0];

    j -= 2;
    k += 2 * step;
}
}
