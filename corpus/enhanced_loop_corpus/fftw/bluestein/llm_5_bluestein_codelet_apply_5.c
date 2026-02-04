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
for (i = 0; i < n; ++i) {
    E xi = b[2 * i], xr = b[2 * i + 1];
    E wr = w[2 * i], wi = w[2 * i + 1];
    if (!(xr == 0.0 && xi == 0.0)) {
        ro[i * os] = xr * wr + xi * wi;
        io[i * os] = xi * wr - xr * wi;
    }
}
}
