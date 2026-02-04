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
    // Variant 2: Strided access with reversed traversal order and indirect indexing via pointer arithmetic
    E *op = o;
    const R *xrp = xr;
    const R *xip = xi;
    INT stride = xs;
    for (i = (n - 1) / 2; i > 0; --i) {
        R temp1 = *(xrp + i * stride);
        R temp2 = *(xrp + (n - i) * stride);
        R temp3 = *(xip + i * stride);
        R temp4 = *(xip + (n - i) * stride);
        op[0] = temp1 + temp2;
        op[1] = temp3 + temp4;
        op[2] = temp1 - temp2;
        op[3] = temp3 - temp4;
        sr += op[0];
        si += op[1];
        op += 4;
    }
}
