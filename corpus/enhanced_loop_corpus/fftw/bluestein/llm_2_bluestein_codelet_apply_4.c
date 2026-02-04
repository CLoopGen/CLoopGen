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
    // Variant 1: Consecutive memory access with pointer arithmetic
    E *bp = b;
    const E *Wp = W;
    for (i = 0; i < nb; ++i) {
        E xr = bp[0], xi = bp[1];
        E wr = Wp[0], wi = Wp[1];
        bp[0] = xi * wr + xr * wi;
        bp[1] = xr * wr - xi * wi;
        bp += 2;
        Wp += 2;
    }
}
