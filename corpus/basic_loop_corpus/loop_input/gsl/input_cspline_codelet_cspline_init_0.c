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

double xa[1 << 20];
double ya[1 << 20];
cspline_state_t *state;
size_t i;
size_t sys_size;

void init_vars() {
    const size_t n = (1 << 20) - 2;
    sys_size = n;

    state = (cspline_state_t *)calloc(1, sizeof(cspline_state_t));
    if (!state) exit(1);

    state->c = (double *)calloc(n, sizeof(double));
    state->g = (double *)calloc(n, sizeof(double));
    state->diag = (double *)calloc(n, sizeof(double));
    state->offdiag = (double *)calloc(n, sizeof(double));

    if (!state->c || !state->g || !state->diag || !state->offdiag) {
        exit(1);
    }

    for (size_t idx = 0; idx < n + 2; ++idx) {
        xa[idx] = (double)(idx * 2);
        ya[idx] = (double)(idx * idx);
    }
}