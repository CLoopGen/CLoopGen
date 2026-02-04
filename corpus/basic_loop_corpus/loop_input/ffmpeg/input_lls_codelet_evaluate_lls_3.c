#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct LLSModel {
    double covariance[36][36] __attribute__((aligned(32)));
    double coeff[32][32] __attribute__((aligned(32)));
    double variance[32];
    int indep_count;
    void (*update_lls)(struct LLSModel *, const double *);
    double (*evaluate_lls)(struct LLSModel *, const double *, int);
} LLSModel;

LLSModel *m;
double *param;
int order;
int i;
double out;

void init_vars() {
    m = aligned_alloc(32, sizeof(LLSModel));
    param = aligned_alloc(32, 32 * sizeof(double));

    order = 31;

    for (int j = 0; j < 36; ++j) {
        for (int k = 0; k < 36; ++k) {
            m->covariance[j][k] = (j == k) ? 1.0 : 0.01;
        }
    }

    for (int j = 0; j < 32; ++j) {
        for (int k = 0; k < 32; ++k) {
            m->coeff[j][k] = 1.0 / (1 + abs(j - k));
        }
        m->variance[j] = 1.0;
    }

    m->indep_count = 32;
    m->update_lls = NULL;
    m->evaluate_lls = NULL;

    for (int j = 0; j <= order; ++j) {
        param[j] = 1.0;
    }

    out = 0.0;
    i = 0;
}