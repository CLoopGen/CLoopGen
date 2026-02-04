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
    // Introduce loop-carried dependence via accumulation to create RAW dependency across iterations
    double prev_g_val = 0.0;
    for (i = 0; i < sys_size - 1; i++) {
        const double h_i = xa[i + 1] - xa[i];
        const double h_ip1 = xa[i + 2] - xa[i + 1];
        const double ydiff_i = ya[i + 1] - ya[i];
        const double ydiff_ip1 = ya[i + 2] - ya[i + 1];
        const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
        const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;

        // Create loop-carried RAW dependency: current iteration depends on previous g value
        const double adjusted_term = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i) + prev_g_val;

        state->offdiag[i] = h_ip1;
        state->diag[i] = 2. * (h_ip1 + h_i);
        state->g[i] = adjusted_term;

        // Update carried variable for next iteration (RAW dependence)
        prev_g_val = state->g[i];
    }
}
