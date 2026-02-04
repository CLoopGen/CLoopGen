#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t n;
    double *range;
    double *sum;
} gsl_histogram_pdf;

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *generated_bin_array;
static double *generated_sum_array;
static double *generated_range_stub1;
static double *generated_range_stub2;
static gsl_histogram_pdf static_p;
static gsl_histogram static_h;
gsl_histogram_pdf *p = &static_p;
gsl_histogram *h = &static_h;
size_t i;
size_t n;
double mean;
double sum;

void init_vars() {
    n = 10000000; // ~80 MB of data (10M * 8 bytes per double), adjust for ~0.01 sec runtime

    generated_bin_array = (double*)calloc(n, sizeof(double));
    generated_sum_array = (double*)calloc(n + 1, sizeof(double)); // p->sum[i+1] accesses up to index n
    generated_range_stub1 = (double*)malloc(sizeof(double));
    generated_range_stub2 = (double*)malloc(sizeof(double));

    if (!generated_bin_array || !generated_sum_array || !generated_range_stub1 || !generated_range_stub2) {
        exit(1);
    }

    for (size_t idx = 0; idx < n; idx++) {
        generated_bin_array[idx] = 1.0 + (idx % 100) * 0.01;
    }

    h->n = n;
    h->range = generated_range_stub1;
    h->bin = generated_bin_array;

    p->n = n + 1;
    p->range = generated_range_stub2;
    p->sum = generated_sum_array;

    mean = 50.5;
    sum = 0.0;
}