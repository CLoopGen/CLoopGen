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
for (; i < vl + 4; ++i) {
    R x0;
    if (i >= 0) {
        x0 = *r0;
        r0 += ivs;
        *cr = x0;
        cr += ovs;
        *ci = ((E)0.);
        ci += ovs;
    }
}
}
