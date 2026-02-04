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
    // Variant 1: Consecutive Memory Access (array elements accessed in contiguous order)
    // Assume xstride, ystride, wstride are 1; use pointer arithmetic for consecutive access
    double *px = x;
    double *py = y;
    double *pw = w;
    for (i = 0; i < n; i++) {
        const double wi = *pw;
        if (wi > 0) {
            W += wi;
            wm_x += (*px - wm_x) * (wi / W);
            wm_y += (*py - wm_y) * (wi / W);
        }
        px += xstride;
        py += ystride;
        pw += wstride;
    }
}
