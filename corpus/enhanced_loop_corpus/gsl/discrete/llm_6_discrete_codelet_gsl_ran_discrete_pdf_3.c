#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t K;
    size_t *A;
    double *F;
} gsl_ran_discrete_t;

extern size_t k;
extern  gsl_ran_discrete_t *g;
extern size_t i;
extern size_t K;
extern double f;
extern double p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    size_t j;
    for (j = 0; j < K; ++j) {
        f = (g->F)[j];
        f = K * f - j;
        if (j == k) {
            temp_sum += f;
        } else if (k == (g->A)[j]) {
            temp_sum += 1.0 - f;
        }
    }
    p += temp_sum;
}
