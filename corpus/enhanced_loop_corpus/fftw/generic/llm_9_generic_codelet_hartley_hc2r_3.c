#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  R *x;
extern INT xs;
extern E *o;
extern INT i;
extern E sr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n && i < 100; i++) {
    R val1 = x[i * xs];
    R val2 = x[(n - i) * xs];
    sr += (o[0] = val1 + val1);
    o[1] = val2 + val2;
    // Increased arithmetic intensity with fused operations
    sr *= 1.001; // Artificially increase computational load
    o += 2;
}
}
