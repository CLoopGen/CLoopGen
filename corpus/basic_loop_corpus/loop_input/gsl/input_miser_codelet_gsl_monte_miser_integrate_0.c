#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_DOUBLES (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double xl[TOTAL_DOUBLES];
double xu[TOTAL_DOUBLES];
size_t dim;
size_t i;
double vol;

void init_vars() {
    dim = TOTAL_DOUBLES;
    vol = 1.0;
    for (size_t idx = 0; idx < dim; idx++) {
        xl[idx] = (double)(idx % 100);
        xu[idx] = xl[idx] + 1.0 + (double)(idx % 3);
    }
}