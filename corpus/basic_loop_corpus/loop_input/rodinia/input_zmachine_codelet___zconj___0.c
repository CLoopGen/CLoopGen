#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stddef.h>

typedef struct {
    double re;
    double im;
} complex;

complex *zp;
int len;
int i;

void init_vars() {
    len = 8388608; // Approximately 128 MB of data (8 bytes * 2 per complex * 8M elements)
    zp = (complex*)aligned_alloc(32, len * sizeof(complex));
    if (!zp) {
        exit(1);
    }
    for (int idx = 0; idx < len; idx++) {
        zp[idx].re = (double)(idx % 1000) / 10.0;
        zp[idx].im = (double)(idx % 1000) / 10.0 + 1.0;
    }
    i = 0;
}