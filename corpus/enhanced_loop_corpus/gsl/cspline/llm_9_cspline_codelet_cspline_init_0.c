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
    for (i = 0; i < sys_size; i += 2) {
        if (i + 1 < sys_size) {
            // Unroll two iterations
            const double h_i0 = xa[i + 1] - xa[i];
            const double h_ip1_0 = xa[i + 2] - xa[i + 1];
            const double ydiff_i0 = ya[i + 1] - ya[i];
            const double ydiff_ip1_0 = ya[i + 2] - ya[i + 1];
            const double g_i0 = (h_i0 != 0.) ? 1.0 / h_i0 : 0.0;
            const double g_ip1_0 = (h_ip1_0 != 0.) ? 1.0 / h_ip1_0 : 0.0;

            state->offdiag[i] = h_ip1_0;
            state->diag[i] = 2.0 * (h_ip1_0 + h_i0);
            state->g[i] = 3.0 * (ydiff_ip1_0 * g_ip1_0 - ydiff_i0 * g_i0);

            const double h_i1 = xa[i + 2] - xa[i + 1];
            const double h_ip1_1 = xa[i + 3] - xa[i + 2];
            const double ydiff_i1 = ya[i + 2] - ya[i + 1];
            const double ydiff_ip1_1 = ya[i + 3] - ya[i + 2];
            const double g_i1 = (h_i1 != 0.) ? 1.0 / h_i1 : 0.0;
            const double g_ip1_1 = (h_ip1_1 != 0.) ? 1.0 / h_ip1_1 : 0.0;

            state->offdiag[i + 1] = h_ip1_1;
            state->diag[i + 1] = 2.0 * (h_ip1_1 + h_i1);
            state->g[i + 1] = 3.0 * (ydiff_ip1_1 * g_ip1_1 - ydiff_i1 * g_i1);
        } else {
            // Handle last odd element
            const double h_i = xa[i + 1] - xa[i];
            const double h_ip1 = xa[i + 2] - xa[i + 1];
            const double ydiff_i = ya[i + 1] - ya[i];
            const double ydiff_ip1 = ya[i + 2] - ya[i + 1];
            const double g_i = (h_i != 0.) ? 1.0 / h_i : 0.0;
            const double g_ip1 = (h_ip1 != 0.) ? 1.0 / h_ip1 : 0.0;
            state->offdiag[i] = h_ip1;
            state->diag[i] = 2.0 * (h_ip1 + h_i);
            state->g[i] = 3.0 * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
        }
    }
}
