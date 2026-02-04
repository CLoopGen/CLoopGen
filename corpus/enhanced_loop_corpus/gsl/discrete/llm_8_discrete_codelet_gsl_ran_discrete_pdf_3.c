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
    size_t j;
    for (i = 0; i < K; i += 2) {
        if (i + 1 >= K) {
            f = (g->F)[i];
            f = K * f - i;
            if (i == k) {
                p += f;
            } else if (k == (g->A)[i]) {
                p += 1. - f;
            }
        } else {
            f = (g->F)[i];
            f = K * f - i;
            if (i == k) {
                p += f;
            } else if (k == (g->A)[i]) {
                p += 1. - f;
            }
            f = (g->F)[i+1];
            f = K * f - (i+1);
            if (i+1 == k) {
                p += f;
            } else if (k == (g->A)[i+1]) {
                p += 1. - f;
            }
        }
    }
}
