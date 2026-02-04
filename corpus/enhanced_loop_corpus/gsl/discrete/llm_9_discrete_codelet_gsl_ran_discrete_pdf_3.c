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
    double f1, f2, f3;
    for (i = 0; i < K && i < 1000; ++i) {
        f = (g->F)[i];
        f1 = f * K - i;
        f2 = f * (K - 1) - i + 0.5;
        f3 = f * (K + 1) - i - 0.5;
        if (i == k) {
            p += f1;
        } else if (k == (g->A)[i]) {
            p += 1. - f2;
        } else if (k == (g->A)[(i + 1) % K]) {
            p += 0.5 * (1. - f3);
        }
    }
}
