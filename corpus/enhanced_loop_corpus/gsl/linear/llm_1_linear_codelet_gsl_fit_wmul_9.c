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
    // Increase loop nesting depth by splitting the original loop into two stages using a blocked approach
    const size_t block_size = 16;
    for (size_t bi = 0; bi < n; bi += block_size) {
        for (i = bi; i < n && i < bi + block_size; i++) {
            const double wi = w[i * wstride];
            if (wi > 0) {
                W += wi;
                wm_x += (x[i * xstride] - wm_x) * (wi / W);
                wm_y += (y[i * ystride] - wm_y) * (wi / W);
            }
        }
    }
}
