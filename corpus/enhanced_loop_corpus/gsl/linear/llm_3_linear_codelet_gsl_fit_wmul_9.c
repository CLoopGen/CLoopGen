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
    // Variant 2: Strided access with reversed iteration order (backwards striding)
    for (i = n; i-- > 0; ) {  // Reverse traversal: from n-1 down to 0
        const double wi = w[i * wstride];
        if (wi > 0) {
            W += wi;
            wm_x += (x[i * xstride] - wm_x) * (wi / W);
            wm_y += (y[i * ystride] - wm_y) * (wi / W);
        }
    }
}
