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
    // Variant 1: Consecutive memory access with array base pointer arithmetic
    // We precompute starting pointers to enable consecutive, forward traversal
    double * restrict offdiag = state->offdiag;
    double * restrict diag = state->diag;
    double * restrict g = state->g;
    const double * restrict xa_local = xa;
    const double * restrict ya_local = ya;
    
    for (i = 0; i < sys_size - 1; i++) {
        const double h_i = xa_local[i + 1] - xa_local[i];
        const double h_ip1 = xa_local[i + 2] - xa_local[i + 1];
        const double ydiff_i = ya_local[i + 1] - ya_local[i];
        const double ydiff_ip1 = ya_local[i + 2] - ya_local[i + 1];
        const double g_i = (h_i != 0.) ? 1. / h_i : 0.;
        const double g_ip1 = (h_ip1 != 0.) ? 1. / h_ip1 : 0.;
        
        offdiag[i] = h_ip1;
        diag[i] = 2. * (h_ip1 + h_i);
        g[i] = 3. * (ydiff_ip1 * g_ip1 - ydiff_i * g_i);
    }
}
