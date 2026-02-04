#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE (1 << 20)

size_t lmax;
double x;
double csphase;
double u;
double uinv;
double uinv2;
double xbyu;
size_t l;
size_t m;
size_t k;
size_t idxmm;
double plm;
double pmm;
double pm1;
double pm2;
double twomm1;

double result_array[ARRAY_SIZE];
double result_deriv_array[ARRAY_SIZE];
double result_deriv2_array[ARRAY_SIZE];

void init_vars() {
    lmax = 400;
    x = 0.75;
    csphase = -1.0;
    u = 0.66;
    uinv = 1.0 / u;
    uinv2 = uinv * uinv;
    xbyu = x * uinv;

    idxmm = 0;
    twomm1 = 1.0;
    pmm = 1.0;
    pm1 = 0.0;
    pm2 = 0.0;
    plm = 0.0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        result_array[i] = 0.0;
        result_deriv_array[i] = 0.0;
        result_deriv2_array[i] = 0.0;
    }
}