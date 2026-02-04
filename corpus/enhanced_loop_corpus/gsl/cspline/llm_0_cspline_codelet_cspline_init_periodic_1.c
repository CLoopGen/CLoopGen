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

extern  double xa[];
extern  double ya[];
extern cspline_state_t *state;
extern size_t i;
extern size_t sys_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < sys_size - 1; j++) {
        const double h_i = xa[j + 1] - xa[j];
        const double h_ip1 = xa[j + 2] - xa[j + 1];
        const double ydiff_i = ya[j + 1] - ya[j];
        const double ydiff_ip1 = ya[j + 2] - ya[j + 1];
        const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
        const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;
        state->offdiag[j] = h_ip1;
        state->diag[j] = 2. * (h_ip1 + h_i);
        state->g[j] = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
    }
}
