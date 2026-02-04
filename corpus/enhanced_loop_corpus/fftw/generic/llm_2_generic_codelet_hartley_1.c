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
    // Variant 1: Consecutive memory access with precomputed indices and local stride
    INT idx1, idx2;
    R *xrp = xr;
    R *xip = xi;
    E *op = o;
    INT stride = xs;
    for (i = 1; i + i < n; ++i) {
        idx1 = i * stride;
        idx2 = (n - i) * stride;
        op[0] = xrp[idx1] + xrp[idx2];
        op[1] = xip[idx1] + xip[idx2];
        op[2] = xrp[idx1] - xrp[idx2];
        op[3] = xip[idx1] - xip[idx2];
        sr += op[0];
        si += op[1];
        op += 4;
    }
}
