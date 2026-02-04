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
    size_t step = 2;
    for (i = 0; i < s->dim; i += step) {
        s->x[i] = 0.;
        if (i + 1 < s->dim) {
            s->x[i + 1] = 0.;
        }
    }
}
