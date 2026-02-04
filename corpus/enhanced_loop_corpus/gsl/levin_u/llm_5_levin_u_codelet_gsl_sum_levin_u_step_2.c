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
    for (j = n - 1; j >= 0; j--) {
        double c = factor * (j + 1) / (n + 1);
        factor *= ratio;
        w->q_den[j] = w->q_den[j + 1] - c * w->q_den[j];
        w->q_num[j] = w->q_num[j + 1] - c * w->q_num[j];
        if (j < n / 2) {
            for (i = 0; i <= n / 2; i++) {
                w->dq_den[((i) * (nmax + 1) + (j))] = w->dq_den[((i) * (nmax + 1) + (j + 1))] - c * w->dq_den[((i) * (nmax + 1) + (j))];
                w->dq_num[((i) * (nmax + 1) + (j))] = w->dq_num[((i) * (nmax + 1) + (j + 1))] - c * w->dq_num[((i) * (nmax + 1) + (j))];
            }
        } else {
            for (i = n / 2 + 1; i < n; i++) {
                w->dq_den[((i) * (nmax + 1) + (j))] = w->dq_den[((i) * (nmax + 1) + (j + 1))] - c * w->dq_den[((i) * (nmax + 1) + (j))];
                w->dq_num[((i) * (nmax + 1) + (j))] = w->dq_num[((i) * (nmax + 1) + (j + 1))] - c * w->dq_num[((i) * (nmax + 1) + (j))];
            }
        }
        w->dq_den[((n) * (nmax + 1) + (j))] = w->dq_den[((n) * (nmax + 1) + (j + 1))];
        w->dq_num[((n) * (nmax + 1) + (j))] = w->dq_num[((n) * (nmax + 1) + (j + 1))];
    }
}
