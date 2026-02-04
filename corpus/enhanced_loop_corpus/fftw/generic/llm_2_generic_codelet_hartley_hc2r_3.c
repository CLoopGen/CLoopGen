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
for (i = 1; i + i < n; ++i) {
    INT idx1 = i * xs;
    INT idx2 = (n - i) * xs;
    sr += (o[0] = x[idx1] + x[idx1]);
    o[1] = x[idx2] + x[idx2];
    o += 2;
}
}
