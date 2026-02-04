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
R prev_cr = 0.0; // Introduce loop-carried dependency via scalar
for (; i < vl + 4; ++i) {
    R x0;
    x0 = *r0;
    r0 += ivs;
    *cr = x0 + prev_cr; // RAW and loop-carried WAW dependency: current write depends on prior iteration's value
    prev_cr = *cr;      // Update for next iteration
    cr += ovs;
    *ci = ((E)0.);
    ci += ovs;
}
}
