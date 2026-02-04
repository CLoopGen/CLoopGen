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
for (i = 1; i + i < n; ++i) {
    R a, b;
    a = xr[i * xs];
    b = xr[(n - i) * xs];
    R sum = a + b;
    R diff = b - a;
    sr += sum;
    o[0] = sum;
    o[1] = diff;
    o += 2;
}
}
