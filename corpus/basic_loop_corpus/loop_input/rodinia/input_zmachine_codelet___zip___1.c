#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    len = 2097152; // ~32 MB of input data (2M * 16 bytes per complex * 2 arrays)

    zp1 = (complex*)aligned_alloc(32, len * sizeof(complex));
    zp2 = (complex*)aligned_alloc(32, len * sizeof(complex));

    for (int j = 0; j < len; j++) {
        zp1[j].re = (double)(j % 100) / 100.0;
        zp1[j].im = (double)(j % 100) / 100.0;
        zp2[j].re = (double)((j + 10) % 100) / 100.0;
        zp2[j].im = (double)((j + 20) % 100) / 100.0;
    }

    sum.re = 0.0;
    sum.im = 0.0;
    i = 0;
}