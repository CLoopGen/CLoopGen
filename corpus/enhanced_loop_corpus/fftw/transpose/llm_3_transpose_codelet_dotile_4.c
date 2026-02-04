#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

extern INT n0l;
extern INT n0u;
extern INT n1l;
extern INT n1u;
extern R *I;
extern INT s0;
extern INT s1;
extern INT i0;
extern INT i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT stride = (s0 > s1) ? s1 : s0;
for (i0 = n0l; i0 < n0u; ++i0) {
    for (i1 = n1l; i1 < n1u; ++i1) {
        INT base_src = i1 * s0 + i0 * s1;
        INT base_dst = i1 * s1 + i0 * s0;
        R temp[2];
        temp[0] = I[base_src];
        temp[1] = I[base_src + 1];
        I[base_src] = I[base_dst];
        I[base_src + 1] = I[base_dst + 1];
        I[base_dst] = temp[0];
        I[base_dst + 1] = temp[1];
    }
}
}
