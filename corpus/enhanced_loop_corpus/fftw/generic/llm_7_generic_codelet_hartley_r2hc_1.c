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
R temp_sr = sr;
for (i = 1; i + i < n; ++i) {
    R a = xr[i * xs];
    R b = xr[(n - i) * xs];
    E val = a + b;
    temp_sr += val;
    o[0] = val;
    o[1] = b - a;
    o += 2;
}
sr = temp_sr;
}
