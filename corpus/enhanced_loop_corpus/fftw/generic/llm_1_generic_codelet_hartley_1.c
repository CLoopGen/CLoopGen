#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  R *xr;
extern  R *xi;
extern INT xs;
extern E *o;
extern INT i;
extern E sr;
extern E si;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i + i < n; ++i) {
    INT j;
    for (j = 0; j < 1; ++j) {
        sr += (o[0] = xr[i * xs] + xr[(n - i) * xs]);
        si += (o[1] = xi[i * xs] + xi[(n - i) * xs]);
        o[2] = xr[i * xs] - xr[(n - i) * xs];
        o[3] = xi[i * xs] - xi[(n - i) * xs];
        o += 4;
    }
}
}
