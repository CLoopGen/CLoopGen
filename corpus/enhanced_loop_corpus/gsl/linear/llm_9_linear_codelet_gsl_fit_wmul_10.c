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
    // Variant 2: Reduced computational intensity with increased memory access and conditional elimination
    // Trip count is doubled by splitting each element into two partial updates, decreasing arithmetic per memory access
    // This increases memory-bound behavior and reduces computational intensity

    size_t i;
    for (i = 0; i < 2 * n; i++) {
        const size_t idx = i / 2;  // Each original element processed in two steps
        const double wi = w[idx * wstride];

        // Skip update if weight is non-positive
        if (!(wi > 0)) continue;

        if (i % 2 == 0) {
            // First half: update W and begin incremental update of wm_dx2
            const double dx = x[idx * xstride] - wm_x;
            const double temp = dx * dx;
            W += wi;
            const double ratio = wi / W;
            wm_dx2 += (temp - wm_dx2) * ratio;
        } else {
            // Second half: update wm_dxdy using same terms
            const double dx = x[idx * xstride] - wm_x;
            const double dy = y[idx * ystride] - wm_y;
            const double temp = dx * dy;
            const double ratio = wi / W;
            wm_dxdy += (temp - wm_dxdy) * ratio;
        }
    }
}
