#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ri;
extern R *ii;
extern INT i;
extern INT n;
extern INT is;
extern R *w;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        E xr0 = ri[i * is], xi0 = ii[i * is];
        E wr0 = w[2 * i], wi0 = w[2 * i + 1];
        b[2 * i] = xr0 * wr0 + xi0 * wi0;
        b[2 * i + 1] = xi0 * wr0 - xr0 * wi0;

        E xr1 = ri[(i + 1) * is], xi1 = ii[(i + 1) * is];
        E wr1 = w[2 * (i + 1)], wi1 = w[2 * (i + 1) + 1];
        b[2 * (i + 1)] = xr1 * wr1 + xi1 * wi1;
        b[2 * (i + 1) + 1] = xi1 * wr1 - xr1 * wi1;
    } else {
        E xr = ri[i * is], xi = ii[i * is];
        E wr = w[2 * i], wi = w[2 * i + 1];
        b[2 * i] = xr * wr + xi * wi;
        b[2 * i + 1] = xi * wr - xr * wi;
    }
}
}
