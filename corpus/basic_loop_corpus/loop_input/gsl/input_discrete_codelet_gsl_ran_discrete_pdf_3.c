#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t K;
    size_t *A;
    double *F;
} gsl_ran_discrete_t;

size_t k;
gsl_ran_discrete_t *g;
size_t i;
size_t K;
double f;
double p;

void init_vars() {
    K = 16777216; // ~134MB of data (16M * (8+8) bytes), target ~0.01s runtime

    g = (gsl_ran_discrete_t*)malloc(sizeof(gsl_ran_discrete_t));
    if (!g) exit(1);

    g->K = K;
    g->A = (size_t*)malloc(K * sizeof(size_t));
    g->F = (double*)malloc(K * sizeof(double));
    
    if (!g->A || !g->F) exit(1);

    for (size_t idx = 0; idx < K; ++idx) {
        g->A[idx] = rand() % K;
        g->F[idx] = (double)(rand() % 1000) / 1000.0;
    }

    k = rand() % K;
    p = 0.0;
    i = 0;
    f = 0.0;
}