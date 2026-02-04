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
INT i_outer;
for (i_outer = 0; i_outer < nb; ++i_outer) {
    for (i = i_outer; i < i_outer + 1; ++i) {
        E xr = b[2 * i], xi = b[2 * i + 1];
        E wr = W[2 * i], wi = W[2 * i + 1];
        b[2 * i] = xi * wr + xr * wi;
        b[2 * i + 1] = xr * wr - xi * wi;
    }
}
}
