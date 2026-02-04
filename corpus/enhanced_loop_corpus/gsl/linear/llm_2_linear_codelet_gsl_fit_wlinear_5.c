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
    // Variant 1: Consecutive memory access with array base pointers advanced by stride
    double *w_ptr = w;
    double *x_ptr = x;
    double *y_ptr = y;
    for (i = 0; i < n; i++) {
        const double wi = *w_ptr;
        if (wi > 0) {
            const double dx = *x_ptr - wm_x;
            const double dy = *y_ptr - wm_y;
            const double d = dy - b * dx;
            d2 += wi * d * d;
        }
        w_ptr += wstride;
        x_ptr += xstride;
        y_ptr += ystride;
    }
}
