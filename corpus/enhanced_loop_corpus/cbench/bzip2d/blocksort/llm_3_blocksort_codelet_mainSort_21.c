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
    // Variant 2: Memory Access Pattern Modification - Indirect access via pointer arithmetic
    // Replace direct array indexing with pointers to create indirect memory access pattern
    // Eliminate while by using bounded iteration with early exit via if-break in for

    UInt32 *ftab_base = ftab;
    Int32 *ro = runningOrder;

    for (i = h; i <= 255; i++) {
        vv = ro[i];
        Int32 target_freq = ftab_base[(vv + 1) << 8] - ftab_base[vv << 8];
        Int32 j = i;
        Int32 moved = 0;

        // Simulate the while loop behavior using a counted downward traversal without while
        // Limit iterations to prevent infinite behavior, realistic since h >= 1
        for (Int32 step = (i - (h - 1)) / h; step > 0; step--) {
            Int32 prev_j = j - h;
            Int32 candidate = ro[prev_j];
            Int32 candidate_freq = ftab_base[(candidate + 1) << 8] - ftab_base[candidate << 8];

            if (candidate_freq <= target_freq) break;

            ro[j] = candidate;
            j = prev_j;
            moved = 1;
        }

        ro[j] = vv;
    }
}
