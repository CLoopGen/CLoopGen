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
        E prev_xr = b[0], prev_xi = b[1];
        E wr = W[0], wi = W[1];
        b[0] = prev_xi * wr + prev_xr * wi;
        b[1] = prev_xr * wr - prev_xi * wi;

        for (i = 1; i < nb; ++i) {
            E xr = b[2 * i], xi = b[2 * i + 1];
            E wr = W[2 * i], wi = W[2 * i + 1];
            E dep_r = prev_xr * wr; 
            E dep_i = prev_xi * wi; 
            b[2 * i] = xi * wr + dep_r;
            b[2 * i + 1] = xr * wr - dep_i;
            prev_xr = xr;
            prev_xi = xi;
        }
    }
}
