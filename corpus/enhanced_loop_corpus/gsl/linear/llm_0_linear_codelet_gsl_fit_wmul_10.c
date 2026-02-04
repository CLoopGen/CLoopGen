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
    for (size_t j = 0; j < n; j++) {
        for (i = j; i < n && (i == j); i++) { // Artificially increase depth with constrained inner loop
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
}
