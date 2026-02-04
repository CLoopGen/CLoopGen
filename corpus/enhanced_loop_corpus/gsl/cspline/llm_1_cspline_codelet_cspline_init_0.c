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
    if (sys_size > 0) {
        for (i = 0; i < sys_size; i += 2) {
            // Process two iterations at a time to simulate deeper logical nesting via unrolling
            {
                const size_t idx = i;
                if (idx < sys_size) {
                    const double h_i = xa[idx + 1] - xa[idx];
                    const double h_ip1 = xa[idx + 2] - xa[idx + 1];
                    const double ydiff_i = ya[idx + 1] - ya[idx];
                    const double ydiff_ip1 = ya[idx + 2] - ya[idx + 1];
                    const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
                    const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;
                    state->offdiag[idx] = h_ip1;
                    state->diag[idx] = 2. * (h_ip1 + h_i);
                    state->g[idx] = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
                }
            }
            {
                const size_t idx = i + 1;
                if (idx < sys_size) {
                    const double h_i = xa[idx + 1] - xa[idx];
                    const double h_ip1 = xa[idx + 2] - xa[idx + 1];
                    const double ydiff_i = ya[idx + 1] - ya[idx];
                    const double ydiff_ip1 = ya[idx + 2] - ya[idx + 1];
                    const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
                    const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;
                    state->offdiag[idx] = h_ip1;
                    state->diag[idx] = 2. * (h_ip1 + h_i);
                    state->g[idx] = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
                }
            }
        }
    }
}
