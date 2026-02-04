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
    if (i % 2 == 0) {
        sr += (o[0] = x[i * xs] + x[i * xs]);
        o[1] = x[(n - i) * xs] + x[(n - i) * xs];
        o += 2;
    } else {
        sr += x[i * xs] * 2.0;
        o[0] = x[(n - i) * xs] * 2.0;
        o += 1;
    }
}
}
