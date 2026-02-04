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
    // Variant 1: Consecutive memory access with pointer arithmetic
    double *xp = x;
    double *wp = w;
    double *yp = y;
    size_t stride_x = xstride;
    size_t stride_w = wstride;
    size_t stride_y = ystride;

    for (i = 0; i < n; i++) {
        const double wi = *wp;
        if (wi > 0) {
            W += wi;
            wm_x += (*xp - wm_x) * (wi / W);
            wm_y += (*yp - wm_y) * (wi / W);
        }
        xp += stride_x;
        wp += stride_w;
        yp += stride_y;
    }
}
