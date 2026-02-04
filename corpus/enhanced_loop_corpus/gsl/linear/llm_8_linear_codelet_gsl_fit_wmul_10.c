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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // The loop now processes two elements per iteration to reduce overhead and increase arithmetic density
    size_t i;
    const size_t step = 2;
    const size_t remainder = n % step;
    const size_t limit = n - remainder;

    for (i = 0; i < limit; i += step) {
        const double wi1 = w[i * wstride];
        const double wi2 = w[(i + 1) * wstride];

        if (wi1 > 0) {
            const double dx1 = x[i * xstride] - wm_x;
            const double dy1 = y[i * ystride] - wm_y;
            const double old_W = W;
            W += wi1;
            const double ratio1 = wi1 / W;
            wm_dx2 += (dx1 * dx1 - wm_dx2) * ratio1;
            wm_dxdy += (dx1 * dy1 - wm_dxdy) * ratio1;
        }

        if (wi2 > 0) {
            const double dx2 = x[(i + 1) * xstride] - wm_x;
            const double dy2 = y[(i + 1) * ystride] - wm_y;
            const double old_W = W;
            W += wi2;
            const double ratio2 = wi2 / W;
            wm_dx2 += (dx2 * dx2 - wm_dx2) * ratio2;
            wm_dxdy += (dx2 * dy2 - wm_dxdy) * ratio2;
        }
    }

    // Handle remaining elements
    for (; i < n; i++) {
        const double wi = w[i * wstride];
        if (wi > 0) {
            const double dx = x[i * xstride] - wm_x;
            const double dy = y[i * ystride] - wm_y;
            W += wi;
            wm_dx2 += (dx * dx - wm_dx2) * (wi / W);
            wm_dxdy += (dx * dy - wm_dxdy) * (wi / W);
        }
    }
}
