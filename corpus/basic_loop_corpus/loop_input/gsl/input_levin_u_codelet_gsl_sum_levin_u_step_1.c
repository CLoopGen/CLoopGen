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

size_t n = 1000;
size_t nmax = 1000;
gsl_sum_levin_u_workspace *w;
unsigned int i;

void init_vars() {
    w = (gsl_sum_levin_u_workspace*)malloc(sizeof(gsl_sum_levin_u_workspace));
    w->size = nmax + 1;
    w->i = 0;
    w->terms_used = 0;
    w->sum_plain = 0.0;

    size_t total_size = (nmax + 1) * (nmax + 1);

    w->q_num = (double*)calloc(total_size, sizeof(double));
    w->q_den = (double*)calloc(total_size, sizeof(double));
    w->dq_num = (double*)calloc(total_size, sizeof(double));
    w->dq_den = (double*)calloc(total_size, sizeof(double));
    w->dsum = (double*)calloc(nmax + 1, sizeof(double));

    for (size_t idx = 0; idx <= nmax; idx++) {
        w->q_den[idx] = 1.0;
    }
}