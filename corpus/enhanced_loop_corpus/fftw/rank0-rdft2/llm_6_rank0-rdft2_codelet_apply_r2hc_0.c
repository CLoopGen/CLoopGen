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
    x1 = *r0;
    r0 += ivs;
    x2 = *r0;
    r0 += ivs;
    x3 = *r0;
    r0 += ivs;

    // Introduce artificial loop-carried dependency via reuse of x0 across iterations
    static R prev_x0 = 0.0;
    R temp = x0 + prev_x0; // RAW dependency: read after write from previous iteration
    prev_x0 = x0;

    *cr = temp;
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
