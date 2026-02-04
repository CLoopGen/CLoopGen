#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT i;
extern INT nb;
extern R *W;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (unrolling-like pattern, stride of 4)
    // Simulates a scenario where elements are accessed with gaps (e.g., processing every other complex pair)
    INT step = 2;
    for (i = 0; i < nb; i += step) {
        INT idx_b = 2 * i;
        INT idx_W = 2 * i;
        E xr0 = b[idx_b],     xi0 = b[idx_b + 1];
        E wr0 = W[idx_W],     wi0 = W[idx_W + 1];
        b[idx_b]     = xi0 * wr0 + xr0 * wi0;
        b[idx_b + 1] = xr0 * wr0 - xi0 * wi0;

        if (i + 1 < nb) {
            INT idx_b1 = idx_b + 2;
            INT idx_W1 = idx_W + 2;
            E xr1 = b[idx_b1],   xi1 = b[idx_b1 + 1];
            E wr1 = W[idx_W1],   wi1 = W[idx_W1 + 1];
            b[idx_b1]     = xi1 * wr1 + xr1 * wi1;
            b[idx_b1 + 1] = xr1 * wr1 - xi1 * wi1;
        }
    }
}
