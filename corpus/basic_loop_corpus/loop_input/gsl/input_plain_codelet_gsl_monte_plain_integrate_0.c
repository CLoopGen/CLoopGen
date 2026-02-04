#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_DOUBLE (1)
#define TOTAL_DOUBLES (DATA_SIZE_MB * 1024 * 1024 / sizeof(double))
#define DIM (TOTAL_DOUBLES / 2)

double xl[DIM];
double xu[DIM];
size_t dim = DIM;
double vol = 1.0;
size_t i;

void init_vars() {
    for (size_t idx = 0; idx < dim; idx++) {
        xl[idx] = (double)(idx % 17) * 0.5;
        xu[idx] = xl[idx] + (double)(idx % 13) + 1.0;
    }
    vol = 1.0;
    i = 0;
}