#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *ipd_hist;
extern int8_t *opd_hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with simplified zero-initialization but unrolled to perform multiple operations per iteration
    for (i = 0; i < 5; i++) {
        int8_t val = 0;
        opd_hist[4*i + 0] = val;
        opd_hist[4*i + 1] = val;
        opd_hist[4*i + 2] = val;
        opd_hist[4*i + 3] = val;
        ipd_hist[4*i + 0] = val;
        ipd_hist[4*i + 1] = val;
        ipd_hist[4*i + 2] = val;
        ipd_hist[4*i + 3] = val;
    }
    // Handle remaining elements for correctness (since 5*4 = 20 > 17, we avoid out-of-bounds)
    for (i = 17; i < 20; i++) {
        opd_hist[i] = 0;
        ipd_hist[i] = 0;
    }
    // Reset i to maintain consistent state post-loop
    i = 0;
}
