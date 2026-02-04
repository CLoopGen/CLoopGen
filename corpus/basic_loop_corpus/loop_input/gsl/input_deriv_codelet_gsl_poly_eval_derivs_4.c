#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64

double c[DATA_SIZE_MB * (1 << 20) / sizeof(double)];
size_t lenc = DATA_SIZE_MB * (1 << 20) / sizeof(double);
double res[DATA_SIZE_MB * (1 << 20) / sizeof(double)];
size_t lenres = DATA_SIZE_MB * (1 << 20) / sizeof(double);
size_t i;
size_t n;
size_t nmax;

void init_vars() {
    for (size_t idx = 0; idx < lenc; idx++) {
        c[idx] = (double)(idx + 1) * 0.5;
    }
    memset(res, 0, lenres * sizeof(double));
    i = 0;
    n = 0;
    nmax = 0;
}