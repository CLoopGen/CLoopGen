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
    for (j = 0; j < 1; j++) {
        for (i = 0; i < s->dim; i++) {
            s->x[i] = 0.;
        }
    }
}
