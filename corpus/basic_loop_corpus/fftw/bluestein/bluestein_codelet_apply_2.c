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
for (i = 0; i < n; ++i) {
    E xr = ri[i * is], xi = ii[i * is];
    E wr = w[2 * i], wi = w[2 * i + 1];
    b[2 * i] = xr * wr + xi * wi;
    b[2 * i + 1] = xi * wr - xr * wi;
}

}
