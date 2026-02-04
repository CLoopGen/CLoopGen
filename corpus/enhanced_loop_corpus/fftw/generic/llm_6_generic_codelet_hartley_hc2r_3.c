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
    E temp1 = x[i * xs] + x[i * xs];
    E temp2 = x[(n - i) * xs] + x[(n - i) * xs];
    sr += temp1;
    o[0] = temp1;
    o[1] = temp2;
    o += 2;
}
}
