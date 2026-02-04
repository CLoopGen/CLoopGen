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
    for (i = 0; i < n; i += 2) {
        for (size_t k = 0; k < 2 && (i + k) < n; k++) {
            const size_t idx = i + k;
            const double wi = w[idx * wstride];
            if (wi > 0) {
                const double dx = x[idx * xstride] - wm_x;
                const double dy = y[idx * ystride] - wm_y;
                W += wi;
                wm_dx2 += (dx * dx - wm_dx2) * (wi / W);
                wm_dxdy += (dx * dy - wm_dxdy) * (wi / W);
            }
        }
    }
}
