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

size_t n = 1024;
size_t nmax = 1024;
double factor = 1.0;
double ratio = 0.99;
unsigned int i;
int j;

gsl_sum_levin_u_workspace *w;

static double *alloc_aligned_double_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(double)) != 0) {
        return NULL;
    }
    return (double *)ptr;
}

void init_vars() {
    w = (gsl_sum_levin_u_workspace *)calloc(1, sizeof(gsl_sum_levin_u_workspace));
    if (!w) exit(1);

    w->size = nmax;
    w->i = 0;
    w->terms_used = 0;
    w->sum_plain = 0.0;

    w->q_num = alloc_aligned_double_array(nmax + 2);
    w->q_den = alloc_aligned_double_array(nmax + 2);
    w->dq_num = alloc_aligned_double_array((nmax + 1) * (nmax + 2));
    w->dq_den = alloc_aligned_double_array((nmax + 1) * (nmax + 2));
    w->dsum = alloc_aligned_double_array(nmax + 1);

    if (!w->q_num || !w->q_den || !w->dq_num || !w->dq_den || !w->dsum) {
        exit(1);
    }

    for (size_t idx = 0; idx < nmax + 2; idx++) {
        w->q_num[idx] = 1.0 + idx * 0.001;
        w->q_den[idx] = 1.0 + idx * 0.002;
    }

    for (size_t idx = 0; idx < (nmax + 1) * (nmax + 2); idx++) {
        w->dq_num[idx] = 1.0 + idx * 0.00001;
        w->dq_den[idx] = 1.0 + idx * 0.00002;
    }

    factor = 1.0;
    ratio = 0.99;
}