#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct {
    double re;
    double im;
} complex;

complex *zp;
complex s;
complex *out;
int len;
int i;
double t_re;
double t_im;

void init_vars() {
    len = 1 << 20; // Approximately 1 million elements, ~16MB total data

    zp = (complex *)aligned_alloc(32, len * sizeof(complex));
    out = (complex *)aligned_alloc(32, len * sizeof(complex));

    for (int j = 0; j < len; j++) {
        zp[j].re = (double)rand() / RAND_MAX;
        zp[j].im = (double)rand() / RAND_MAX;
    }

    s.re = 0.7071;
    s.im = 0.7071;

    t_re = 0.0;
    t_im = 0.0;
    i = 0;
}