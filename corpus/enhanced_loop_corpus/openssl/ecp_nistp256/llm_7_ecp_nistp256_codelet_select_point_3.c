#include <stdio.h>

#include <inttypes.h>

typedef uint64_t u64;

typedef u64 smallfelem[4];

extern  u64 idx;
extern unsigned int size;
extern  smallfelem pre_comp[16][3];
extern unsigned int i;
extern unsigned int j;
extern u64 *outlimbs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        const u64 *inlimbs = (u64 *)&pre_comp[i][0][0];
        u64 mask = i ^ idx;
        mask |= mask >> 4;
        mask |= mask >> 2;
        mask |= mask >> 1;
        mask &= 1;
        mask--;
        // Eliminate loop-carried dependency by unrolling and reordering
        // Introduce artificial WAR-like pattern via temporary write-read
        u64 t0 = inlimbs[0] & mask;
        u64 t1 = inlimbs[1] & mask;
        u64 t2 = inlimbs[2] & mask;
        u64 t3 = inlimbs[3] & mask;

        // Create intra-loop dependencies not carried across iterations
        t0 ^= t1; t1 ^= t2; t2 ^= t3; t3 ^= t0;

        outlimbs[0] |= t0;
        outlimbs[1] |= t1;
        outlimbs[2] |= t2;
        outlimbs[3] |= t3;

        // Continue for remaining elements with staggered indexing to break alignment
        for (j = 4; j < 4 * 3; j++) {
            u64 val = inlimbs[j] & mask;
            // Make current iteration's store dependent on prior value in output (RAW)
            val ^= (outlimbs[(j - 1) % (4 * 3)]) >> 63;
            outlimbs[j % (4 * 3)] |= val;
        }
    }
}
