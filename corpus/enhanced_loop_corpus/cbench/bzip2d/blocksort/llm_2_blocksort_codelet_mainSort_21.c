#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;
extern Int32 j;
extern Int32 runningOrder[256];
extern Int32 vv;
extern Int32 h;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Memory Access Pattern Modification - Use strided access with fixed step unrolling
    // Instead of decrementing j by h in a while loop, we precompute possible positions and use a for loop
    // This changes memory access to be more predictable with stride h

    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        Int32 base_vv_freq = ftab[(vv + 1) << 8] - ftab[vv << 8];
        Int32 pos = i;

        // Unrolled forward-stride replacement using indirect comparisons at stride h
        // Simulate the while logic without while: iterate backward in steps of h using for
        for (Int32 k = i; k > h - 1; k -= h) {
            Int32 prev_index = k - h;
            Int32 curr_freq = ftab[(runningOrder[prev_index] + 1) << 8] - ftab[runningOrder[prev_index] << 8];
            if (curr_freq <= base_vv_freq) break;
            runningOrder[k] = runningOrder[prev_index];
            pos = prev_index;
        }
        runningOrder[pos] = vv;
    }
}
