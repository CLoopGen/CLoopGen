#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ci;
extern INT i;
extern INT vl;
extern INT ovs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i <= vl; i += 4) {
        for (INT unroll = 0; unroll < 4; ++unroll) {
            *ci = ((E)0.);
            ci += ovs;
        }
    }
}
