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

int max_order = 32;

double lpc[32][32] __attribute__((aligned(32)));

int j;

LLSModel *m;

void init_vars() {
    m = aligned_alloc(32, sizeof(LLSModel));
    if (!m) exit(1);

    for (int i = 0; i < 36; i++) {
        for (int k = 0; k < 36; k++) {
            m->covariance[i][k] = (double)(i + k);
        }
    }

    for (int i = 0; i < 32; i++) {
        for (int k = 0; k < 32; k++) {
            m->coeff[i][k] = 0.0;
            lpc[i][k] = (double)(i * 32 + k + 1) * 0.5;
        }
    }

    for (int i = 0; i < 32; i++) {
        m->variance[i] = (double)i * i;
    }

    m->indep_count = 16;
    m->update_lls = NULL;
    m->evaluate_lls = NULL;

    max_order = 32;
    j = 0;
}