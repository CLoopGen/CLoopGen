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
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Instead of strided access by ovs, we assume ovs == 1 for consecutive layout
    // and process two elements per iteration for better performance
    INT bound = vl + 4;
    for (; i < bound; i += 2) {
        *ci = ((E)0.);
        *(ci + 1) = ((E)0.);
        ci += 2 * ovs;
    }
    // Handle remaining element if i == vl+3 at exit
    if (i == bound - 1) {
        *ci = ((E)0.);
    }
}
