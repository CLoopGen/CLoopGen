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
    R x[4];
    // Load all values first with independent accesses (reducing immediate dependencies)
    x[0] = *r0;
    r0 += ivs;
    x[1] = *r0;
    r0 += ivs;
    x[2] = *r0;
    r0 += ivs;
    x[3] = *r0;
    r0 += ivs;

    // Eliminate sequential store pattern by reordering stores to break potential WAW and WAR hazards
    // Store in reverse order to cr and ci with interleaving removed
    *(cr + 3*ovs) = x[3];
    *(cr + 2*ovs) = x[2];
    *(cr + 1*ovs) = x[1];
    *cr = x[0];

    *(ci + 3*ovs) = ((E)0.);
    *(ci + 2*ovs) = ((E)0.);
    *(ci + 1*ovs) = ((E)0.);
    *ci = ((E)0.);

    // Update pointers in one step to remove per-store pointer arithmetic (reduces loop-carried dependency on cr/ci)
    cr += 4 * ovs;
    ci += 4 * ovs;
}
}
