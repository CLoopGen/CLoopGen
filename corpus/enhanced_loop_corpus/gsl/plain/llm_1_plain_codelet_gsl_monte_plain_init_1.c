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
    if (s->dim > 0) {
        i = 0;
        for (;;) {
            s->x[i] = 0.;
            i++;
            if (i >= s->dim) break;
        }
    }
}
