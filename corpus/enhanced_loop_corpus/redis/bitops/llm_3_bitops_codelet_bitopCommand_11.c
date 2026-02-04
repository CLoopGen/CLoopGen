#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long numkeys;
extern unsigned long i;
extern unsigned long **lp;
extern unsigned long *lres;
extern size_t k;
extern unsigned long lcommon_bits[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Access memory with a fixed stride across iterations to simulate non-contiguous access
    // This variant unrolls the conceptual access into a strided traversal by processing multiple indices per iteration
    const size_t stride = 2;
    const size_t unroll_factor = 4;

    // Process elements in chunks of 2 to demonstrate strided behavior
    for (i = 1; i < numkeys; i += stride) {
        // Handle up to 'stride' iterations manually to show strided access
        for (size_t s = 0; s < stride && (i + s) < numkeys; s++) {
            unsigned long idx = i + s;
            // Strided access: still use k+0, k+1, etc., but less frequently due to outer stride
            lcommon_bits[0] |= (lres[0] & lp[idx][k + 0]);
            lcommon_bits[1] |= (lres[1] & lp[idx][k + 1]);
            lcommon_bits[2] |= (lres[2] & lp[idx][k + 2]);
            lcommon_bits[3] |= (lres[3] & lp[idx][k + 3]);

            lres[0] ^= lp[idx][k + 0];
            lres[1] ^= lp[idx][k + 1];
            lres[2] ^= lp[idx][k + 2];
            lres[3] ^= lp[idx][k + 3];
        }
    }
}
