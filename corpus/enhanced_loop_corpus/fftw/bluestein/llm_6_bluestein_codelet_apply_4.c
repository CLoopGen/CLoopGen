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
        E temp_real = xi * wr + xr * wi;
        E temp_imag = xr * wr - xi * wi;
        b[2 * i] = temp_real;
        b[2 * i + 1] = temp_imag;
    }
}
