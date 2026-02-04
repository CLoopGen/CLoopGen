#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef R E;

extern INT n;
extern  E *x;
extern  R *w;
extern INT i;
extern E rr;
extern E ri;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i + i < n; ++i) {
    INT idx = (i << 1); // equivalent to i * 2
    rr += x[idx - 2] * w[idx - 2];
    ri += x[idx - 1] * w[idx - 1];
}
}
