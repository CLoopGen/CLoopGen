#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

double *x;
size_t xstride;
double *w;
size_t wstride;
double *y;
size_t ystride;
size_t n;
double wm_x;
double wm_y;
size_t i;
double d2;
double b;

static double internal_x[65536];
static double internal_w[65536];
static double internal_y[65536];

void init_vars() {
    n = 65536;
    xstride = 1;
    wstride = 1;
    ystride = 1;
    wm_x = 1.5;
    wm_y = 2.0;
    d2 = 0.0;
    b = 0.75;

    for (size_t idx = 0; idx < n; idx++) {
        internal_x[idx] = (double)(idx % 100) + 0.5;
        internal_w[idx] = (double)(idx % 3) * 0.5;
        internal_y[idx] = (double)((idx + 42) % 100) + 0.25;
    }

    x = internal_x;
    w = internal_w;
    y = internal_y;
}