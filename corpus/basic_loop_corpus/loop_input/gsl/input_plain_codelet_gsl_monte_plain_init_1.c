#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    size_t dim;
    double *x;
} gsl_monte_plain_state;

gsl_monte_plain_state *s;
size_t i;

void init_vars() {
    s = (gsl_monte_plain_state *)malloc(sizeof(gsl_monte_plain_state));
    s->dim = 134217728 / sizeof(double);  // ~1GB / 8 = ~16M elements, yields ~0.01s on modern CPU
    s->x = (double *)calloc(s->dim, sizeof(double));
}

void loop();