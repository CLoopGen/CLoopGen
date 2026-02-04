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
    for (i = 1; i < sys_size - 1; i += 2) {
        const double h_im1 = xa[i] - xa[i - 1];
        const double h_i = xa[i + 1] - xa[i];
        const double h_ip1 = xa[i + 2] - xa[i + 1];
        const double h_ip2 = xa[i + 3] - xa[i + 2];
        const double ydiff_im1 = ya[i] - ya[i - 1];
        const double ydiff_i = ya[i + 1] - ya[i];
        const double ydiff_ip1 = ya[i + 2] - ya[i + 1];
        const double ydiff_ip2 = ya[i + 3] - ya[i + 2];
        const double g_im1 = (h_im1 != 0.) ? 1. / h_im1 : 0.;
        const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
        const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;
        const double g_ip2 = (h_ip2 != 0.) ? 1. / h_ip2 : 0.;

        state->offdiag[i - 1] = h_i;
        state->diag[i - 1] = 2. * (h_i + h_im1);
        state->g[i - 1] = 3. * (ydiff_i * g_i - ydiff_im1 * g_im1);

        if (i + 1 < sys_size - 1) {
            state->offdiag[i] = h_ip1;
            state->diag[i] = 2. * (h_ip1 + h_i);
            state->g[i] = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
        }
    }
}
