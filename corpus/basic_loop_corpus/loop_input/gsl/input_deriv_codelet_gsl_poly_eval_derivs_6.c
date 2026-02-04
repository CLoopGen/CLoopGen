#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE ((DATA_SIZE_MB * 1024 * 1024) / sizeof(double))

double res[ARRAY_SIZE];
size_t i;
size_t nmax = ARRAY_SIZE - 1;
double f;

void init_vars() {
    f = 1.0;
    for (size_t idx = 0; idx < ARRAY_SIZE; idx++) {
        res[idx] = 1.0 + 0.01 * idx;
    }
}