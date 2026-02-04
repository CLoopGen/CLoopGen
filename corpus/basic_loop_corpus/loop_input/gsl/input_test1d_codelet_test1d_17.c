#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

static double *range_data1;
static double *bin_data1;
static double *range_data2;
static double *bin_data2;

gsl_histogram *h;
gsl_histogram *hh;
size_t i;
int status;

void init_vars() {
    size_t num_elements = 397;
    
    range_data1 = (double*)malloc(num_elements * sizeof(double));
    bin_data1 = (double*)malloc(num_elements * sizeof(double));
    range_data2 = (double*)malloc(num_elements * sizeof(double));
    bin_data2 = (double*)malloc(num_elements * sizeof(double));
    
    for (size_t idx = 0; idx < num_elements; idx++) {
        range_data1[idx] = (double)(idx * 2);
        bin_data1[idx] = (double)(idx * 3 + 1);
        range_data2[idx] = (double)(idx * 2);
        bin_data2[idx] = (double)(idx * 3 + 1);
    }
    
    h = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    hh = (gsl_histogram*)malloc(sizeof(gsl_histogram));
    
    h->n = num_elements;
    h->range = range_data1;
    h->bin = bin_data1;
    
    hh->n = num_elements;
    hh->range = range_data2;
    hh->bin = bin_data2;
    
    i = 0;
    status = 0;
}