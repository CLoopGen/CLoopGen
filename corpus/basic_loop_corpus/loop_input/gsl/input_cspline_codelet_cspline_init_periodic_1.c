#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double *c;
    double *g;
    double *diag;
    double *offdiag;
} cspline_state_t;

double xa[256000];
double ya[256000];
cspline_state_t *state;
size_t i;
size_t sys_size;

void init_vars() {
    sys_size = 256000 - 1;  // Adjust so that i+2 is valid in loop

    state = (cspline_state_t *)malloc(sizeof(cspline_state_t));
    if (!state) return;

    state->c = (double *)malloc(sys_size * sizeof(double));
    state->g = (double *)malloc(sys_size * sizeof(double));
    state->diag = (double *)malloc(sys_size * sizeof(double));
    state->offdiag = (double *)malloc(sys_size * sizeof(double));

    for (size_t j = 0; j < 256000; j++) {
        xa[j] = (double)(j + 1) * 0.1;
        ya[j] = (double)(j + 1) * 0.1 * 0.1;
    }
}