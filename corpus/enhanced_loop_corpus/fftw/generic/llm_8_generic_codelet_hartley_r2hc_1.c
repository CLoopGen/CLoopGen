#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  R *xr;
extern INT xs;
extern E *o;
extern INT i;
extern E sr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    R a1, b1, a2, b2;
    INT idx1 = i * xs;
    INT idx2 = (n - 1 - i) * xs;
    a1 = xr[idx1];
    b1 = xr[idx2];
    sr += (o[0] = a1 + b1);
    o[1] = b1 - a1;
    if (i + 1 < n) {
        a2 = xr[(i + 1) * xs];
        b2 = xr[(n - 1 - (i + 1)) * xs];
        sr += (o[2] = a2 + b2);
        o[3] = b2 - a2;
    }
    o += 4;
}
}
