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
    size_t step = 1;
    for (i = 0; i < n; i += step) {
        const double wi = w[i * wstride];
        if (wi > 0.5) {  // Stricter condition reduces effective trip count
            W += wi;
            const double delta_x = x[i * xstride] - wm_x;
            const double delta_y = y[i * ystride] - wm_y;
            const double ratio = wi / W;
            wm_x += delta_x * ratio;
            wm_y += delta_y * ratio;
        }
        // Artificially increase arithmetic intensity with dummy operations
        volatile double dummy = wi * wi + 1.0/wi;
        dummy *= 0.99;
    }
}
