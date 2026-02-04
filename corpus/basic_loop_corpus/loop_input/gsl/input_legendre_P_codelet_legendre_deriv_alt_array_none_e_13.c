#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t lmax = 2000;
double x = 0.6;
double csphase = -1.0;
double u = 0.8;
double uinv = 1.25;
double xbyu = 0.6 / 0.8;

size_t l = 0;
size_t m = 0;
size_t k = 0;
size_t idxmm = 0;
double plm = 0.0;
double pmm = 1.0;
double pm1 = 0.0;
double pm2 = 0.0;
double twomm1 = -1.0;

double result_array[4000000];
double result_deriv_array[4000000];

void init_vars() {
    lmax = 2000;
    x = 0.6;
    csphase = -1.0;
    u = 0.8;
    uinv = 1.0 / u;
    xbyu = x * uinv;
    idxmm = 0;
    pmm = 1.0;
    twomm1 = -1.0;

    for (size_t i = 0; i < 4000000; ++i) {
        result_array[i] = 0.0;
        result_deriv_array[i] = 0.0;
    }

    pm1 = 0.0;
    pm2 = 0.0;
    l = 0;
    m = 0;
    k = 0;
}