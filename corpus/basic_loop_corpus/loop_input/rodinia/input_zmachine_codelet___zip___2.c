#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

complex *zp1;
complex *zp2;
int len;
complex sum;
int i;

void init_vars() {
    len = 10000000; // ~160 MB of data (10M * 2 * 8 * 2), adjust for ~0.01 sec runtime

    zp1 = (complex *)aligned_alloc(32, len * sizeof(complex));
    zp2 = (complex *)aligned_alloc(32, len * sizeof(complex));

    for (int j = 0; j < len; j++) {
        zp1[j].re = 1.0;
        zp1[j].im = 0.5;
        zp2[j].re = 0.8;
        zp2[j].im = 0.3;
    }

    sum.re = 0.0;
    sum.im = 0.0;
    i = 0;
}