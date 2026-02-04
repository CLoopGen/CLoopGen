#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t dim;
    double *x;
} gsl_monte_plain_state;

extern gsl_monte_plain_state *s;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < s->dim; i++) {
        s->x[i] = 0.;
        for (j = 1; j <= 3; j++) {
            s->x[i] += (double)(1.0 / (i + j));
        }
    }
}
