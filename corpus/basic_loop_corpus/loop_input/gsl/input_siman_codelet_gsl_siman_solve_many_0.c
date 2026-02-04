#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int n_tries;
    int iters_fixed_T;
    double step_size;
    double k;
    double t_initial;
    double mu_t;
    double t_min;
} gsl_siman_params_t;

gsl_siman_params_t params;
double *probs;
double *sum_probs;
int i;

void init_vars() {
    params.n_tries = 10000000;  // Adjusted to achieve ~0.01 sec runtime
    params.iters_fixed_T = 100;
    params.step_size = 0.1;
    params.k = 1.0;
    params.t_initial = 1000.0;
    params.mu_t = 1.05;
    params.t_min = 1e-6;

    probs = (double*)calloc(params.n_tries, sizeof(double));
    sum_probs = (double*)calloc(params.n_tries, sizeof(double));

    for (int j = 0; j < params.n_tries; ++j) {
        probs[j] = (double)(rand()) / RAND_MAX;
    }

    if (params.n_tries > 0) {
        sum_probs[0] = probs[0];
    }
}