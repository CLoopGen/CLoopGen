#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *r0;
extern R *cr;
extern R *ci;
extern INT i;
extern INT vl;
extern INT ivs;
extern INT ovs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i <= vl; i += 4) {
    R x0, x1, x2, x3;
    INT idx_r = (i - 4) * ivs;
    x0 = r0[idx_r];
    x1 = r0[idx_r + ivs];
    x2 = r0[idx_r + 2*ivs];
    x3 = r0[idx_r + 3*ivs];
    INT idx_c = (i - 4) * ovs * 2;
    cr[idx_c] = x0;
    ci[idx_c] = ((E)0.);
    cr[idx_c + ovs] = x1;
    ci[idx_c + ovs] = ((E)0.);
    cr[idx_c + 2*ovs] = x2;
    ci[idx_c + 2*ovs] = ((E)0.);
    cr[idx_c + 3*ovs] = x3;
    ci[idx_c + 3*ovs] = ((E)0.);
}
}
