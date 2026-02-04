#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *h;
size_t i;
size_t imin;
double min;

static double *alloc_and_init_double_array(size_t size, unsigned int *seed) {
    double *arr = (double*)malloc(size * sizeof(double));
    for (size_t idx = 0; idx < size; ++idx) {
        arr[idx] = (double)(rand_r(seed) % 10000) / 10.0;
    }
    return arr;
}

void init_vars() {
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h->n = 20000000; 

    unsigned int seed = (unsigned int)time(NULL);
    h->range = alloc_and_init_double_array(h->n + 1, &seed);
    h->bin = alloc_and_init_double_array(h->n, &seed);

    i = 0;
    imin = 0;
    min = h->bin[0];

    for (size_t idx = 0; idx < h->n; ++idx) {
        if (h->bin[idx] < min) {
            min = h->bin[idx];
            imin = idx;
        }
    }
}