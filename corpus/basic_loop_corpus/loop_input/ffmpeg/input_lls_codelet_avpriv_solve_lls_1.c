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
int i;
int k;
double (*factor)[36];
double *covar_y;
int count;

void init_vars() {
    count = 1024;

    m = aligned_alloc(32, sizeof(LLSModel));
    for (int idx = 0; idx < 36; idx++) {
        for (int jdx = 0; jdx < 36; jdx++) {
            m->covariance[idx][jdx] = (idx == jdx) ? 1.0 : 0.01;
        }
    }
    for (int idx = 0; idx < 32; idx++) {
        for (int jdx = 0; jdx < 32; jdx++) {
            m->coeff[idx][jdx] = 0.0;
        }
        m->variance[idx] = 1.0;
    }
    m->indep_count = 0;
    m->update_lls = NULL;
    m->evaluate_lls = NULL;

    factor = aligned_alloc(32, sizeof(double[count][36]));
    covar_y = aligned_alloc(32, sizeof(double[count + 1]));

    for (int idx = 0; idx < count; idx++) {
        for (int jdx = 0; jdx < 36; jdx++) {
            factor[idx][jdx] = (jdx <= idx) ? ((double)rand() / RAND_MAX) : 0.0;
        }
        if (idx < count) {
            covar_y[idx + 1] = (double)rand() / RAND_MAX;
        }
    }

    i = 0;
    k = 0;
}