#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t size;
    size_t i;
    size_t terms_used;
    double sum_plain;
    double *q_num;
    double *q_den;
    double *dq_num;
    double *dq_den;
    double *dsum;
} gsl_sum_levin_u_workspace;

double *array;
gsl_sum_levin_u_workspace *w;
double variance;
size_t n;
unsigned int i;

void init_vars() {
    n = 10000000; // Adjusted for ~0.01 sec runtime on modern CPU

    array = (double*)calloc(n, sizeof(double));
    w = (gsl_sum_levin_u_workspace*)malloc(sizeof(gsl_sum_levin_u_workspace));
    w->dsum = (double*)calloc(n, sizeof(double));

    for (size_t idx = 0; idx < n; idx++) {
        array[idx] = 1.0 + 0.001 * idx;
        w->dsum[idx] = 1.0 - 0.0001 * idx;
    }

    variance = 0.0;
    i = 0;
}