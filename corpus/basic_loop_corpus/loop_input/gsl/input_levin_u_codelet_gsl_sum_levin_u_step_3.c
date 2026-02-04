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

size_t n = 10000;
size_t nmax = 10000;
double result = 1.5;
unsigned int i;

static double *alloc_or_die(size_t len) {
    double *ptr = (double *)calloc(len, sizeof(double));
    if (!ptr) {
        exit(1);
    }
    return ptr;
}

gsl_sum_levin_u_workspace *w;

void init_vars() {
    w = (gsl_sum_levin_u_workspace *)calloc(1, sizeof(gsl_sum_levin_u_workspace));
    if (!w) exit(1);

    w->size = nmax + 1;
    w->i = 0;
    w->terms_used = 0;
    w->sum_plain = 0.0;

    w->q_num = alloc_or_die(nmax + 1);
    w->q_den = alloc_or_die(nmax + 1);
    w->dq_num = alloc_or_die((nmax + 1) * (nmax + 1));
    w->dq_den = alloc_or_die((nmax + 1) * (nmax + 1));
    w->dsum = alloc_or_die(n + 1);

    for (size_t idx = 0; idx <= nmax; idx++) {
        w->q_den[idx] = 1.0;
    }

    for (size_t row = 0; row <= n; row++) {
        for (size_t col = 0; col <= nmax; col++) {
            w->dq_num[row * (nmax + 1) + col] = 1.0;
            w->dq_den[row * (nmax + 1) + col] = 1.0;
        }
    }
}