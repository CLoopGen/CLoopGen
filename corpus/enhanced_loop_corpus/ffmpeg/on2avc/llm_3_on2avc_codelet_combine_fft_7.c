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
// Use strided access with precomputed base pointers for temporal locality and stride optimization
float *sj, *tk0, *tk1, *hk0, *hk1;
for (i = 0; i < (len4 - 2) >> 1; i++) {
    sj = &s0[j]; tk0 = &t0[k]; tk1 = &t0[k + step]; 
    hk0 = &h0[k]; hk1 = &h0[k + step];

    *d1++ = sj[0] * tk0[0] + sj[1] * tk1[0] +
            sj[0] * t1[k] + sj[1] * t1[k + step] +
            sj[0] * t2[k] + sj[1] * t2[k + step] +
            sj[0] * t3[k] + sj[1] * t3[k + step];

    *d1++ = sj[0] * tk1[0] - sj[1] * tk0[0] +
            sj[0] * t1[k + step] - sj[1] * t1[k] +
            sj[0] * t2[k + step] - sj[1] * t2[k] +
            sj[0] * t3[k + step] - sj[1] * t3[k];

    *d2++ = sj[0] * hk0[0] + sj[1] * hk1[0] +
            sj[0] * h1[k] + sj[1] * h1[k + step] +
            sj[0] * h2[k] + sj[1] * h2[k + step] +
            sj[0] * h3[k] + sj[1] * h3[k + step];

    *d2++ = sj[0] * hk1[0] - sj[1] * hk0[0] +
            sj[0] * h1[k + step] - sj[1] * h1[k] +
            sj[0] * h2[k + step] - sj[1] * h2[k] +
            sj[0] * h3[k + step] - sj[1] * h3[k];

    j -= 2;
    k += 2 * step;
}
}
