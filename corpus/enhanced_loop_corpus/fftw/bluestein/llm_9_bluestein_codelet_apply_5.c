#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ro;
extern R *io;
extern INT i;
extern INT n;
extern INT os;
extern R *w;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        E xi0 = b[2 * i], xr0 = b[2 * i + 1];
        E wr0 = w[2 * i], wi0 = w[2 * i + 1];
        ro[i * os] = xr0 * wr0 + xi0 * wi0;
        io[i * os] = xi0 * wr0 - xr0 * wi0;

        E xi1 = b[2 * (i + 1)], xr1 = b[2 * (i + 1) + 1];
        E wr1 = w[2 * (i + 1)], wi1 = w[2 * (i + 1) + 1];
        ro[(i + 1) * os] = xr1 * wr1 + xi1 * wi1;
        io[(i + 1) * os] = xi1 * wr1 - xr1 * wi1;
    } else {
        E xi = b[2 * i], xr = b[2 * i + 1];
        E wr = w[2 * i], wi = w[2 * i + 1];
        ro[i * os] = xr * wr + xi * wi;
        io[i * os] = xi * wr - xr * wi;
    }
}
}
