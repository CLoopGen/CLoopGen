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
    E temp_rr = x[0] * w[0];
    E temp_ir = x[1] * w[0];
    E temp_ri = x[2] * w[1];
    E temp_ii = x[3] * w[1];
    rr += temp_rr;
    ir += temp_ir;
    ri += temp_ri;
    ii += temp_ii;
    x += 4;
    w += 2;
}
}
