#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce loop-carried dependence with cumulative update (WAW and RAW)
    active_caches[0] = 0;
    for (k = 1; k < 2; k++) {
        active_caches[k] = 0;
        active_caches[k] += active_caches[k-1]; // Loop-carried RAW: current depends on prior iteration
    }
    // Final unroll-like fix-up to ensure both are zero eventually
    active_caches[0] = 0;
}
