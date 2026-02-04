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
for (i = 0; i < vl; i += 4) {
    R values[4];
    INT base_in = i * ivs;
    values[0] = r0[base_in];
    values[1] = r0[base_in + ivs];
    values[2] = r0[base_in + 2*ivs];
    values[3] = r0[base_in + 3*ivs];
    INT base_out = i * ovs * 2;
    for (INT j = 0; j < 4; ++j) {
        cr[base_out + j * ovs] = values[j];
        ci[base_out + j * ovs] = ((E)0.);
    }
}
}
