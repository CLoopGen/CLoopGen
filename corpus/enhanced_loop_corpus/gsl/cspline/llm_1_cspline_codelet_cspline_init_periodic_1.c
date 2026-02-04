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
    if (sys_size > 1) {
        for (size_t k = 0; k < sys_size - 1; k++) {
            const double h_i = xa[k + 1] - xa[k];
            if (k + 2 >= sys_size) break;
            const double h_ip1 = xa[k + 2] - xa[k + 1];
            const double ydiff_i = ya[k + 1] - ya[k];
            const double ydiff_ip1 = ya[k + 2] - ya[k + 1];
            const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
            const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;
            state->offdiag[k] = h_ip1;
            state->diag[k] = 2. * (h_ip1 + h_i);
            state->g[k] = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
        }
    }
}
