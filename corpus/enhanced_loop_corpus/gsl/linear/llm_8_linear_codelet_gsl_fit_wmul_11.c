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
        const double wi1 = w[i * wstride];
        if (wi1 > 0) {
            const double dx1 = x[i * xstride] - wm_x;
            const double dy1 = y[i * ystride] - wm_y;
            const double d1 = (wm_y - b * wm_x) + (dy1 - b * dx1);
            d2 += wi1 * d1 * d1;
        }
        if (i + 1 < n) {
            const double wi2 = w[(i + 1) * wstride];
            if (wi2 > 0) {
                const double dx2 = x[(i + 1) * xstride] - wm_x;
                const double dy2 = y[(i + 1) * ystride] - wm_y;
                const double d2_val = (wm_y - b * wm_x) + (dy2 - b * dx2);
                d2 += wi2 * d2_val * d2_val;
            }
        }
    }
}
