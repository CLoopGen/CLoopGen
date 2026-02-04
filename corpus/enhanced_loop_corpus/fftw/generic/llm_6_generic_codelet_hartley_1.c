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
INT j;
R temp_r1, temp_r2, temp_i1, temp_i2;
sr = 0.0;
si = 0.0;
for (i = 1; i + i < n; ++i) {
    j = i * xs;
    temp_r1 = xr[j];
    temp_r2 = xr[(n - i) * xs];
    temp_i1 = xi[j];
    temp_i2 = xi[(n - i) * xs];
    o[0] = temp_r1 + temp_r2;
    o[1] = temp_i1 + temp_i2;
    o[2] = temp_r1 - temp_r2;
    o[3] = temp_i1 - temp_i2;
    sr += o[0];
    si += o[1];
    o += 4;
}
}
