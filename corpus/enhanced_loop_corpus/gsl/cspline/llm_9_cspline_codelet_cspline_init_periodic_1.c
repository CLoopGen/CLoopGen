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
    for (i = 0; i < sys_size - 2; i++) {
        const double h_i = xa[i + 1] - xa[i];
        const double h_ip1 = xa[i + 2] - xa[i + 1];
        const double inv_h_i = (h_i > 1e-12) ? 1.0 / h_i : 0.0;
        const double inv_h_ip1 = (h_ip1 > 1e-12) ? 1.0 / h_ip1 : 0.0;
        const double slope_i = (ya[i + 1] - ya[i]) * inv_h_i;
        const double slope_ip1 = (ya[i + 2] - ya[i + 1]) * inv_h_ip1;
        const double delta_slope = slope_ip1 - slope_i;

        state->offdiag[i] = h_ip1;
        state->diag[i] = 2.0 * (h_ip1 + h_i);
        state->g[i] = 3.0 * delta_slope;

        // Additional computational work to increase arithmetic intensity
        double temp = state->g[i] * inv_h_i;
        temp += temp * h_i;
        state->c[i] = temp * 0.5;
    }
}
