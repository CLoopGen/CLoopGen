#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double c[1 << 20];
size_t lenc = 1 << 20;
double x = 1.5;
double res[1 << 20];
size_t i;
size_t nmax = 1000;
size_t k;
size_t l;
size_t lmax;

void init_vars() {
    for (size_t idx = 0; idx < lenc; idx++) {
        c[idx] = (double)(idx % 100) / 100.0;
        res[idx] = 0.0;
    }
    x = 0.99;
    nmax = 1000;
    i = 0;
    k = 0;
    l = 0;
    lmax = 0;
}