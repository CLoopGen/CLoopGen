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

extern gsl_siman_params_t params;
extern double *probs;
extern double *sum_probs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (params.n_tries > 1) {
    sum_probs[1] = sum_probs[0] + probs[1];
    for (i = 2; i < params.n_tries; ++i) {
        sum_probs[i] = sum_probs[i - 1] + probs[i];
    }
}
}
