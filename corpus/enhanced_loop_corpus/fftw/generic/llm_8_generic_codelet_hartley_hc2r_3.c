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
for (i = 0; i < n; i += 3) {
    sr += (o[0] = x[i * xs] + x[i * xs] + x[i * xs]);
    o[1] = x[(n - i - 1) * xs] + x[(n - i - 1) * xs] + x[(n - i - 1) * xs];
    o[2] = x[(i + 1) * xs] * x[(i + 1) * xs]; // Additional computation
    o += 3;
}
}
