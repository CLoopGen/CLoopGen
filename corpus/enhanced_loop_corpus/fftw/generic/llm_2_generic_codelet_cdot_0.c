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
extern E ir;
extern E ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i + i < n; ++i) {
    INT idx_x = (i << 2);        // Strided access: x[4*i]
    INT idx_w = (i << 1);        // Strided access: w[2*i]
    rr += x[idx_x] * w[idx_w];
    ir += x[idx_x + 1] * w[idx_w];
    ri += x[idx_x + 2] * w[idx_w + 1];
    ii += x[idx_x + 3] * w[idx_w + 1];
}
}
