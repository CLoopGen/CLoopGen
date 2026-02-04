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
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via ovs, write 4 consecutive doubles
    for (i = 4; i <= vl; i += 4) {
        ci[0] = ((E)0.);
        ci[1] = ((E)0.);
        ci[2] = ((E)0.);
        ci[3] = ((E)0.);
        ci += 4 * ovs;  // Advance pointer by 4 strides for next iteration
    }
}
