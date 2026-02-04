#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

gsl_histogram *h;
size_t i;
size_t n;

void init_vars() {
    n = 10000000;  // ~80 MB for bin array (10M * 8 bytes), targets ~0.01 sec on modern CPU
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    h->n = n;
    h->range = (double*)calloc(n + 1, sizeof(double));
    h->bin = (double*)calloc(n, sizeof(double));
}

// DO NOT include main or extra comments as per instructions