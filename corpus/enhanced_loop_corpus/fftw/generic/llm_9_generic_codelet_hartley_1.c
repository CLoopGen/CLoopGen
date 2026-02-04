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
for (i = 1; i < n && 2*i < n; i += 2) {
    INT idx1 = i * xs;
    INT idx2 = (n - i) * xs;
    INT idx3 = (i + 1) * xs;
    INT idx4 = (n - i - 1) * xs;

    // First pair
    sr += (o[0] = xr[idx1] + xr[idx2]);
    si += (o[1] = xi[idx1] + xi[idx2]);
    o[2] = xr[idx1] - xr[idx2];
    o[3] = xi[idx1] - xi[idx2];

    // Second pair (if valid)
    if (i + 1 + (i + 1) < n) {
        sr += (o[4] = xr[idx3] + xr[idx4]);
        si += (o[5] = xi[idx3] + xi[idx4]);
        o[6] = xr[idx3] - xr[idx4];
        o[7] = xi[idx3] - xi[idx4];
        o += 8;
    } else {
        o += 4;
    }
}
}
