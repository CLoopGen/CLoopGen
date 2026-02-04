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
for (INT outer = 0; outer < n; ++outer) {
    for (INT inner = 0; inner < 1; ++inner) {
        INT i = outer;
        E xi = b[2 * i], xr = b[2 * i + 1];
        E wr = w[2 * i], wi = w[2 * i + 1];
        ro[i * os] = xr * wr + xi * wi;
        io[i * os] = xi * wr - xr * wi;
    }
}
}
