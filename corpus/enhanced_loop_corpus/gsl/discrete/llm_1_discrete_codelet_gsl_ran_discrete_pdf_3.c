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
    for (size_t outer = 0; outer < K; ++outer) {
        for (i = outer; i < outer + 1 && i < K; ++i) {
            f = (g->F)[i];
            f = K * f - i;
            if (i == k) {
                p += f;
            } else if (k == (g->A)[i]) {
                p += 1. - f;
            }
        }
    }
}
