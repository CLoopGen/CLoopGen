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
for (i = 0; i < nb; ++i) {
    E xr = b[2 * i], xi = b[2 * i + 1];
    E wr = W[2 * i], wi = W[2 * i + 1];
    if (xr == 0 || wr == 0) {
        b[2 * i] = xi * wr;
        b[2 * i + 1] = -xi * wi;
        continue;
    }
    if (xi == 0 || wi == 0) {
        b[2 * i] = xr * wi;
        b[2 * i + 1] = xr * wr;
        continue;
    }
    b[2 * i] = xi * wr + xr * wi;
    b[2 * i + 1] = xr * wr - xi * wi;
}
}
