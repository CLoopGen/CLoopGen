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
E local_rr = rr;
E local_ii = ii;
for (i = 1; i + i < n; ++i) {
    local_rr = local_rr + x[0] * w[0];
    local_ii = local_ii + x[1] * w[1];
    x += 2;
    w += 2;
}
rr = local_rr;
ii = local_ii;
}
