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
for (i = 1; i < n / 2; ++i) {
    R a, b;
    a = xr[i * xs];
    b = xr[(n - i) * xs];
    if (a > b) {
        sr += (o[0] = a + b);
        o[1] = b - a;
    } else {
        o[0] = 0.0;
        o[1] = 0.0;
    }
    o += 2;
}
}
