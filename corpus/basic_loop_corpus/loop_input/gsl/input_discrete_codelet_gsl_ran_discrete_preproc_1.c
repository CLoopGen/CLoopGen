#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t K;
    size_t *A;
    double *F;
} gsl_ran_discrete_t;

size_t Kevents;
size_t k;
gsl_ran_discrete_t *g;

void init_vars() {
    Kevents = 16777216; // ~16.7 million elements, targets ~0.01 sec on modern CPU

    g = (gsl_ran_discrete_t*)malloc(sizeof(gsl_ran_discrete_t));
    g->K = Kevents;
    g->A = (size_t*)calloc(Kevents, sizeof(size_t));
    g->F = (double*)malloc(Kevents * sizeof(double));

    for (size_t i = 0; i < Kevents; ++i) {
        g->F[i] = (double)(i * 2);
    }
}