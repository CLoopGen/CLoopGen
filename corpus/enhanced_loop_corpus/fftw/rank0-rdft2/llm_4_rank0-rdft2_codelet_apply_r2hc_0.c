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
    x0 = *r0;
    r0 += ivs;
    if (i % 8 == 0) {
        x1 = *r0;
        r0 += ivs;
        x2 = *r0;
        r0 += ivs;
        x3 = *r0;
        r0 += ivs;
    } else {
        x1 = ((E)0.);
        x2 = ((E)0.);
        x3 = ((E)0.);
        r0 += 3 * ivs;
    }
    *cr = x0;
    cr += ovs;
    *ci = ((E)0.);
    ci += ovs;
    *cr = x1;
    cr += ovs;
    *ci = ((E)0.);
    ci += ovs;
    *cr = x2;
    cr += ovs;
    *ci = ((E)0.);
    ci += ovs;
    *cr = x3;
    cr += ovs;
    *ci = ((E)0.);
    ci += ovs;
}
}
