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
// Change to strided access with reversed traversal and alternating write pattern
INT stride = 2;
for (; i < (vl + 4) / stride; ++i) {
    R x0;
    INT idx = (vl + 3) - i * stride;  // Reverse strided index
    x0 = r0[idx * ivs];
    cr[idx * ovs] = x0;
    ci[idx * ovs] = ((E)0.);
}
}
