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
INT j;
for (i = 1; i + i < n; ++i) {
    R a, b;
    if (i >= n - i) continue;
    a = xr[i * xs];
    b = xr[(n - i) * xs];
    sr += (o[0] = a + b);
    o[1] = b - a;
    o += 2;
}
}
