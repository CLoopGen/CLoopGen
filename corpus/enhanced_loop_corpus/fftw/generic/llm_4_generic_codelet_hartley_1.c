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
INT limit = n >> 1;
for (i = 1; i < limit; ++i) {
    INT idx1 = i * xs;
    INT idx2 = (n - i) * xs;
    R xr1 = xr[idx1];
    R xr2 = xr[idx2];
    R xi1 = xi[idx1];
    R xi2 = xi[idx2];
    
    sr += (o[0] = xr1 + xr2);
    si += (o[1] = xi1 + xi2);
    o[2] = xr1 - xr2;
    o[3] = xi1 - xi2;
    o += 4;
}
}
