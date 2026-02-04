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
    INT idx = i * is;
    E xr = ri[idx], xi = ii[idx];
    INT widx = 2 * i;
    E wr = w[widx], wi = w[widx + 1];
    INT bidx = widx;
    b[bidx] = xr * wr + xi * wi;
    b[bidx + 1] = xi * wr - xr * wi;
}
}
