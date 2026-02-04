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
    double *dsum;
} gsl_sum_levin_utrunc_workspace;

size_t n = 10000000;  // ~80MB for two double arrays (q_num, q_den), should run in ~0.01s
double factor = 1.5;
double ratio = 0.999;
int j;

gsl_sum_levin_utrunc_workspace *w;

void init_vars() {
    w = (gsl_sum_levin_utrunc_workspace*)malloc(sizeof(gsl_sum_levin_utrunc_workspace));
    w->size = n + 1;
    w->i = 0;
    w->terms_used = 0;
    w->sum_plain = 0.0;

    w->q_num = (double*)malloc((n + 1) * sizeof(double));
    w->q_den = (double*)malloc((n + 1) * sizeof(double));
    w->dsum = (double*)malloc((n + 1) * sizeof(double));

    for (size_t i = 0; i <= n; i++) {
        w->q_num[i] = 1.0 + 0.001 * i;
        w->q_den[i] = 1.0 + 0.002 * i;
        w->dsum[i] = 0.0;
    }

    factor = 1.5;
    ratio = 0.999;
}