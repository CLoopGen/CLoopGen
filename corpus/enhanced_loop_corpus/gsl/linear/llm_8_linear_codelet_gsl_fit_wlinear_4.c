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
    size_t i;
    for (i = 0; i < n && n > 0; i += 2) {
        const double wi1 = w[i * wstride];
        if (wi1 > 0) {
            const double dx1 = x[i * xstride] - wm_x;
            const double dy1 = y[i * ystride] - wm_y;
            W += wi1;
            wm_dx2 += (dx1 * dx1 - wm_dx2) * (wi1 / W);
            wm_dxdy += (dx1 * dy1 - wm_dxdy) * (wi1 / W);
        }
        if (i + 1 < n) {
            const double wi2 = w[(i + 1) * wstride];
            if (wi2 > 0) {
                const double dx2 = x[(i + 1) * xstride] - wm_x;
                const double dy2 = y[(i + 1) * ystride] - wm_y;
                W += wi2;
                wm_dx2 += (dx2 * dx2 - wm_dx2) * (wi2 / W);
                wm_dxdy += (dx2 * dy2 - wm_dxdy) * (wi2 / W);
            }
        }
    }
}
