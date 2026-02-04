#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

complex *zp1;
complex *zp2;
complex s;
int len;
int i;
double t_re;
double t_im;

void init_vars() {
    len = 16777216; // ~256MB of data: 16777216 elements * 32 bytes per two complex = ~512MB total

    zp1 = (complex*)aligned_alloc(32, len * sizeof(complex));
    zp2 = (complex*)aligned_alloc(32, len * sizeof(complex));

    for (int j = 0; j < len; j++) {
        zp1[j].re = (double)(j % 100) / 100.0;
        zp1[j].im = (double)(j % 101) / 101.0;
        zp2[j].re = (double)(j % 102) / 102.0;
        zp2[j].im = (double)(j % 103) / 103.0;
    }

    double angle = 0.785398; // ~π/4
    s.re = cos(angle);
    s.im = sin(angle);

    i = 0;
    t_re = 0.0;
    t_im = 0.0;
}