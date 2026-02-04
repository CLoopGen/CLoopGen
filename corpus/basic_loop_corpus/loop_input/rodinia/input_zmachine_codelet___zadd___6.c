#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

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
    len = 8000000; // Approximately 192 MB of data (3 arrays × 8 MiB × 2 doubles × 8 bytes)

    zp1 = (complex*)aligned_alloc(32, len * sizeof(complex));
    zp2 = (complex*)aligned_alloc(32, len * sizeof(complex));
    out = (complex*)aligned_alloc(32, len * sizeof(complex));

    for (int idx = 0; idx < len; idx++) {
        zp1[idx].re = (double)(idx % 100) + 0.1;
        zp1[idx].im = (double)(idx % 100) + 0.2;
        zp2[idx].re = (double)((idx + 10) % 100) + 0.3;
        zp2[idx].im = (double)((idx + 10) % 100) + 0.4;
        out[idx].re = 0.0;
        out[idx].im = 0.0;
    }

    i = 0;
}