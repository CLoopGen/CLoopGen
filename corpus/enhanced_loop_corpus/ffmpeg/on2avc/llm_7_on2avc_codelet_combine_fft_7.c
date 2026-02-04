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
    float sum1_real, sum1_imag, sum2_real, sum2_imag;
    for (i = 0; i < (len4 - 2) >> 1; i++) {
        sum1_real = 0.0f;
        sum1_imag = 0.0f;
        sum2_real = 0.0f;
        sum2_imag = 0.0f;

        sum1_real += s0[j + 0] * t0[k + 0];
        sum1_real += s0[j + 1] * t0[k + 1];
        sum1_real += s1[j + 0] * t1[k + 0];
        sum1_real += s1[j + 1] * t1[k + 1];
        sum1_real += s2[j + 0] * t2[k + 0];
        sum1_real += s2[j + 1] * t2[k + 1];
        sum1_real += s3[j + 0] * t3[k + 0];
        sum1_real += s3[j + 1] * t3[k + 1];

        sum1_imag += s0[j + 0] * t0[k + 1];
        sum1_imag -= s0[j + 1] * t0[k + 0];
        sum1_imag += s1[j + 0] * t1[k + 1];
        sum1_imag -= s1[j + 1] * t1[k + 0];
        sum1_imag += s2[j + 0] * t2[k + 1];
        sum1_imag -= s2[j + 1] * t2[k + 0];
        sum1_imag += s3[j + 0] * t3[k + 1];
        sum1_imag -= s3[j + 1] * t3[k + 0];

        sum2_real += s0[j + 0] * h0[k + 0];
        sum2_real += s0[j + 1] * h0[k + 1];
        sum2_real += s1[j + 0] * h1[k + 0];
        sum2_real += s1[j + 1] * h1[k + 1];
        sum2_real += s2[j + 0] * h2[k + 0];
        sum2_real += s2[j + 1] * h2[k + 1];
        sum2_real += s3[j + 0] * h3[k + 0];
        sum2_real += s3[j + 1] * h3[k + 1];

        sum2_imag += s0[j + 0] * h0[k + 1];
        sum2_imag -= s0[j + 1] * h0[k + 0];
        sum2_imag += s1[j + 0] * h1[k + 1];
        sum2_imag -= s1[j + 1] * h1[k + 0];
        sum2_imag += s2[j + 0] * h2[k + 1];
        sum2_imag -= s2[j + 1] * h2[k + 0];
        sum2_imag += s3[j + 0] * h3[k + 1];
        sum2_imag -= s3[j + 1] * h3[k + 0];

        *d1++ = sum1_real;
        *d1++ = sum1_imag;
        *d2++ = sum2_real;
        *d2++ = sum2_imag;

        j -= 2;
        k += 2 * step;
    }
}
