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
extern double wm_x;
extern double wm_y;
extern size_t i;
extern double d2;
extern double b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            const double wi0 = w[i * wstride];
            const double wi1 = w[(i + 1) * wstride];
            if (wi0 > 0) {
                const double dx0 = x[i * xstride] - wm_x;
                const double dy0 = y[i * ystride] - wm_y;
                const double d0 = dy0 - b * dx0;
                d2 += wi0 * d0 * d0;
            }
            if (wi1 > 0) {
                const double dx1 = x[(i + 1) * xstride] - wm_x;
                const double dy1 = y[(i + 1) * ystride] - wm_y;
                const double d1 = dy1 - b * dx1;
                d2 += wi1 * d1 * d1;
            }
        } else {
            const double wi = w[i * wstride];
            if (wi > 0) {
                const double dx = x[i * xstride] - wm_x;
                const double dy = y[i * ystride] - wm_y;
                const double d = dy - b * dx;
                d2 += wi * d * d;
            }
        }
    }
}
