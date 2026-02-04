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
extern E ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i + i < n; ++i) {
    for (INT unroll = 0; unroll < 1; ++unroll) {
        rr += x[0] * w[0];
        ii += x[1] * w[1];
        x += 2;
        w += 2;
    }
}
}
