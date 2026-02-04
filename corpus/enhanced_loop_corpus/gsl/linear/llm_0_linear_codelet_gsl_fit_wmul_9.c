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
    for (i = 0; i < n; i++) {
        const double wi = w[i * wstride];
        if (wi > 0) {
            W += wi;
            wm_x += (x[i * xstride] - wm_x) * (wi / W);
            wm_y += (y[i * ystride] - wm_y) * (wi / W);
        }
        // Introduce an additional inner loop that does nothing but simulate fine-grained work
        for (size_t j = 0; j < 1; j++) {
            // Dummy operation to represent potential future per-element refinement
            volatile size_t dummy = j;
            (void)dummy;
        }
    }
}
