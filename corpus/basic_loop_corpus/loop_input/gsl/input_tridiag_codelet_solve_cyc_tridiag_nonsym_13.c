#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

double abovediag[65536];
size_t a_stride = 1;
double x[65536];
size_t x_stride = 1;
size_t N = 32768;
double *alpha = &abovediag[0];
double *zb = &x[0];
double *zu = &x[0];
double *w = &x[32768]; // offset to avoid overlap
size_t i;
size_t j;

void init_vars() {
    for (size_t idx = 0; idx < 65536; ++idx) {
        abovediag[idx] = 1.0;
    }
    for (size_t idx = 0; idx < 65536; ++idx) {
        x[idx] = 1.0;
    }
    for (size_t idx = 0; idx < 32768; ++idx) {
        w[idx] = 0.0;
    }
    alpha = abovediag;
    zb = x;
    zu = x;
    w = x + 32768;
    N = 32768;
    a_stride = 1;
    x_stride = 1;
}