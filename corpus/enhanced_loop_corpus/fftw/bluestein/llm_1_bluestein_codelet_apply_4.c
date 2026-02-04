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
if (nb > 0) {
    for (i = 0; i < nb; ++i) {
        for (INT j = 0; j < 1; ++j) { // Degenerate inner loop with fixed iteration
            E xr = b[2 * i], xi = b[2 * i + 1];
            E wr = W[2 * i], wi = W[2 * i + 1];
            b[2 * i] = xi * wr + xr * wi;
            b[2 * i + 1] = xr * wr - xi * wi;
        }
    }
}
}
