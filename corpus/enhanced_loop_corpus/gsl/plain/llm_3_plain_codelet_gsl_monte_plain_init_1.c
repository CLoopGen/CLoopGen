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
    size_t *indices = (size_t*)malloc(s->dim * sizeof(size_t));
    for (i = 0; i < s->dim; i++) {
        indices[i] = i;
    }
    for (i = 0; i < s->dim; i++) {
        s->x[indices[i]] = 0.;
    }
    free(indices);
}
