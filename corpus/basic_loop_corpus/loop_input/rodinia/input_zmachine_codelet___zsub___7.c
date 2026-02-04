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
complex *out;
int len;
int i;

void init_vars() {
    len = 20000000; // Approximately 20M elements, ~304 MB total data (20M * 2 * 2 * 8 bytes)

    zp1 = (complex*)aligned_alloc(32, len * sizeof(complex));
    zp2 = (complex*)aligned_alloc(32, len * sizeof(complex));
    out = (complex*)aligned_alloc(32, len * sizeof(complex));

    if (!zp1 || !zp2 || !out) {
        fprintf(stderr, "Final allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        zp1[j].re = 1.0 + j * 0.000001;
        zp1[j].im = 0.5 + j * 0.0000005;
        zp2[j].re = 0.1 + j * 0.000002;
        zp2[j].im = 0.05 + j * 0.0000002;
        out[j].re = 0.0;
        out[j].im = 0.0;
    }
}