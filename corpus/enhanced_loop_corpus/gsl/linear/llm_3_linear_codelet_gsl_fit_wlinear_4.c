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
    // Variant 2: Strided access with reversed traversal (backward iteration)
    for (i = n; i-- > 0; ) {  // Reverse loop: from n-1 down to 0
        const size_t idx = i * xstride;
        const size_t jdx = i * wstride;
        const size_t kdx = i * ystride;
        const double wi = w[jdx];
        if (wi > 0) {
            const double dx = x[idx] - wm_x;
            const double dy = y[kdx] - wm_y;
            W += wi;
            wm_dx2 += (dx * dx - wm_dx2) * (wi / W);
            wm_dxdy += (dx * dy - wm_dxdy) * (wi / W);
        }
    }
}
