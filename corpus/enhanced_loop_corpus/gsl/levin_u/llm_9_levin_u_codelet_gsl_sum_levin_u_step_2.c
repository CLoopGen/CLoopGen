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

extern  size_t n;
extern  size_t nmax;
extern gsl_sum_levin_u_workspace *w;
extern double factor;
extern double ratio;
extern unsigned int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = (n + 3) / 4;
    for (j = n - 1; j >= 0; j -= stride) {
        double c = factor * (j + 1) / (n + 1);
        factor *= ratio;
        w->q_den[j] = w->q_den[j + 1] - c * w->q_den[j];
        w->q_num[j] = w->q_num[j + 1] - c * w->q_num[j];
        for (i = 0; i < n; i++) {
            size_t idx = i * (nmax + 1) + j;
            size_t next_idx = i * (nmax + 1) + j + 1;
            w->dq_den[idx] = w->dq_den[next_idx] - c * w->dq_den[idx];
            w->dq_num[idx] = w->dq_num[next_idx] - c * w->dq_num[idx];
        }
        size_t last_idx_j = n * (nmax + 1) + j;
        size_t last_idx_j1 = n * (nmax + 1) + j + 1;
        w->dq_den[last_idx_j] = w->dq_den[last_idx_j1];
        w->dq_num[last_idx_j] = w->dq_num[last_idx_j1];
    }
}
