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
        for (INT unroll_factor = 0; unroll_factor < 4 && (i - 4 + unroll_factor) <= vl; ++unroll_factor) {
            R x;
            x = *r0;
            r0 += ivs;
            *cr = x;
            cr += ovs;
            *ci = ((E)0.);
            ci += ovs;
        }
    }
}
