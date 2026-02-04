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
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        const double wi1 = w[i * wstride];
        if (wi1 > 0) {
            W += wi1;
            wm_x += (x[i * xstride] - wm_x) * (wi1 / W);
            wm_y += (y[i * ystride] - wm_y) * (wi1 / W);
        }
        if (i + 1 < n) {
            const double wi2 = w[(i + 1) * wstride];
            if (wi2 > 0) {
                W += wi2;
                wm_x += (x[(i + 1) * xstride] - wm_x) * (wi2 / W);
                wm_y += (y[(i + 1) * ystride] - wm_y) * (wi2 / W);
            }
        }
    }
}
