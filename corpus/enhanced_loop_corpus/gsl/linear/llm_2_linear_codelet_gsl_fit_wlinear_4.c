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
    // Variant 1: Consecutive memory access with array base pointer adjustment
    double *x_ptr = x;
    double *w_ptr = w;
    double *y_ptr = y;
    for (i = 0; i < n; i++) {
        const double wi = *w_ptr;
        if (wi > 0) {
            const double dx = *x_ptr - wm_x;
            const double dy = *y_ptr - wm_y;
            W += wi;
            wm_dx2 += (dx * dx - wm_dx2) * (wi / W);
            wm_dxdy += (dx * dy - wm_dxdy) * (wi / W);
        }
        x_ptr += xstride;
        w_ptr += wstride;
        y_ptr += ystride;
    }
}
