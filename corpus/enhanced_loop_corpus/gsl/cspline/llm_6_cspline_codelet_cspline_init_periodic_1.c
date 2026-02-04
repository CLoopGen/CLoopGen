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
    for (i = 0; i < sys_size - 1; i++) {
        const double h_i = xa[i + 1] - xa[i];
        const double h_ip1 = xa[i + 2] - xa[i + 1];
        const double ydiff_i = ya[i + 1] - ya[i];
        const double ydiff_ip1 = ya[i + 2] - ya[i + 1];
        const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
        const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;

        // Introduce a WAW dependency by reordering writes and using temporary variables
        // to delay actual assignment, creating artificial write-after-write pattern
        double temp_offdiag = h_ip1;
        double temp_diag = 2. * (h_ip1 + h_i);
        double temp_g = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);

        // Simulate WAW: write in different order than original, but same final effect
        state->g[i] = temp_g;
        state->offdiag[i] = temp_offdiag;
        state->diag[i] = temp_diag;
    }
}
