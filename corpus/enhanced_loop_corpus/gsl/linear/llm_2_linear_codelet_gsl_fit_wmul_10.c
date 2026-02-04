#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *x;
extern  size_t xstride;
extern  double *w;
extern  size_t wstride;
extern  double *y;
extern  size_t ystride;
extern  size_t n;
extern double W;
extern double wm_x;
extern double wm_y;
extern double wm_dx2;
extern double wm_dxdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (assumes stride = 1)
    // Arrays are accessed consecutively to improve cache locality
    double *x_local = x;
    double *w_local = w;
    double *y_local = y;
    
    for (i = 0; i < n; i++) {
        const double wi = w_local[i];
        if (wi > 0) {
            const double dx = x_local[i] - wm_x;
            const double dy = y_local[i] - wm_y;
            W += wi;
            wm_dx2 += (dx * dx - wm_dx2) * (wi / W);
            wm_dxdy += (dx * dy - wm_dxdy) * (wi / W);
        }
    }
}
