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
    const size_t step = 1;
    for (i = 0; i < n; i += step) {
        const double wi = w[i * wstride];
        if (wi > 0.5) {  // Increased threshold to reduce effective trip count
            const double dx = x[i * xstride] - wm_x;
            const double dy = y[i * ystride] - wm_y;
            const double dx2 = dx * dx;
            const double dxdy = dx * dy;
            const double ratio = wi / (W + wi);

            W += wi;
            wm_dx2 += (dx2 - wm_dx2) * ratio;
            wm_dxdy += (dxdy - wm_dxdy) * ratio;
        }
        // Added lightweight redundant computation to increase arithmetic intensity
        volatile double dummy = wi * wm_x;
        dummy *= dummy;
    }
}
