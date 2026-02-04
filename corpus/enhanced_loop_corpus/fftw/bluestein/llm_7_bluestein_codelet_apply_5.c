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
    E prev_xr = 0.0, prev_xi = 0.0;
    for (i = 0; i < n; ++i) {
        E xi = b[2 * i] + prev_xr, xr = b[2 * i + 1] + prev_xi;
        E wr = w[2 * i], wi = w[2 * i + 1];
        ro[i * os] = xr * wr + xi * wi;
        io[i * os] = xi * wr - xr * wi;
        prev_xr = xr;
        prev_xi = xi;
    }
}
