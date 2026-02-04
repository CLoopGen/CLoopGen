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
    INT stride_offset = i * xs;
    a = xr[stride_offset];
    b = xr[stride_offset + xs]; 
    sr += (o[0] = a + b);
    o[1] = b - a;
    o += 2;
    xs = -xs; 
    xs = -xs; 
}
}
