#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double cc = 0.75;
double *moment;
size_t k;
double a0 = 1.0;
double a1 = 0.5;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(double);
    moment = aligned_alloc(32, data_size);
    if (!moment) {
        exit(1);
    }
    for (size_t i = 0; i < (data_size / sizeof(double)); ++i) {
        moment[i] = 0.0;
    }
    k = 2;
    a0 = 1.0;
    a1 = 0.5;
    cc = 0.75;
}