#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long numkeys;
extern unsigned long i;
extern unsigned long **lp;
extern unsigned long *lres;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — instead of sequential [k+0], [k+1], etc.,
    // access with a fixed stride (e.g., every 8th element) to simulate sparse or strided dataset traversal.
    // This changes access pattern to touch elements further apart, increasing stride.
    const size_t stride = 8;
    for (i = 1; i < numkeys; i++) {
        lres[0] |= lp[i][k + 0 * stride];
        lres[1] |= lp[i][k + 1 * stride];
        lres[2] |= lp[i][k + 2 * stride];
        lres[3] |= lp[i][k + 3 * stride];
    }
}
