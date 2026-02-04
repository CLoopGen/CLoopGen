#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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

static double *alloc_and_init_double_array(size_t len) {
    double *arr = (double*)calloc(len, sizeof(double));
    for (size_t idx = 0; idx < len; idx++) {
        arr[idx] = drand48() * 2.0 - 1.0;
    }
    return arr;
}

void init_vars() {
    n = 8000000;
    xstride = 1;
    wstride = 1;
    ystride = 1;

    wm_x = drand48() * 10.0;
    wm_y = drand48() * 10.0;
    b = drand48() * 2.0 - 1.0;
    d2 = 0.0;

    x = alloc_and_init_double_array(n);
    w = alloc_and_init_double_array(n);
    y = alloc_and_init_double_array(n);

    for (size_t j = 0; j < n; j++) {
        w[j] = drand48(); 
    }

    i = 0;
}