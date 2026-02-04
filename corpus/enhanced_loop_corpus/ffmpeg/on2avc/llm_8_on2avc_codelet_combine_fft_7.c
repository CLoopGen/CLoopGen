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
for (i = 0; i < (len4 - 2) >> 2; i++) {
    float s0j0 = s0[j + 0], s0j1 = s0[j + 1];
    float s1j0 = s1[j + 0], s1j1 = s1[j + 1];
    float s2j0 = s2[j + 0], s2j1 = s2[j + 1];
    float s3j0 = s3[j + 0], s3j1 = s3[j + 1];

    float t0k0 = t0[k + 0], t0k1 = t0[k + 1];
    float t1k0 = t1[k + 0], t1k1 = t1[k + 1];
    float t2k0 = t2[k + 0], t2k1 = t2[k + 1];
    float t3k0 = t3[k + 0], t3k1 = t3[k + 1];

    float h0k0 = h0[k + 0], h0k1 = h0[k + 1];
    float h1k0 = h1[k + 0], h1k1 = h1[k + 1];
    float h2k0 = h2[k + 0], h2k1 = h2[k + 1];
    float h3k0 = h3[k + 0], h3k1 = h3[k + 1];

    float sum1_real = s0j0 * t0k0 + s0j1 * t0k1 +
                     s1j0 * t1k0 + s1j1 * t1k1 +
                     s2j0 * t2k0 + s2j1 * t2k1 +
                     s3j0 * t3k0 + s3j1 * t3k1;

    float sum1_imag = s0j0 * t0k1 - s0j1 * t0k0 +
                     s1j0 * t1k1 - s1j1 * t1k0 +
                     s2j0 * t2k1 - s2j1 * t2k0 +
                     s3j0 * t3k1 - s3j1 * t3k0;

    float sum2_real = s0j0 * h0k0 + s0j1 * h0k1 +
                      s1j0 * h1k0 + s1j1 * h1k1 +
                      s2j0 * h2k0 + s2j1 * h2k1 +
                      s3j0 * h3k0 + s3j1 * h3k1;

    float sum2_imag = s0j0 * h0k1 - s0j1 * h0k0 +
                      s1j0 * h1k1 - s1j1 * h1k0 +
                      s2j0 * h2k1 - s2j1 * h2k0 +
                      s3j0 * h3k1 - s3j1 * h3k0;

    *d1++ = sum1_real;
    *d1++ = sum1_imag;
    *d2++ = sum2_real;
    *d2++ = sum2_imag;

    j -= 4;
    k += 4 * step;
}
}
