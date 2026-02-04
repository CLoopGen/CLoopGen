#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t K;
    size_t *A;
    double *F;
} gsl_ran_discrete_t;

extern size_t Kevents;
extern size_t k;
extern gsl_ran_discrete_t *g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *F = g->F;
    size_t Kev = Kevents;
    double factor = 1.0 / Kev;
    for (k = 0; k < Kev; ++k) {
        F[k] += k;
        F[k] *= factor;
    }
}
