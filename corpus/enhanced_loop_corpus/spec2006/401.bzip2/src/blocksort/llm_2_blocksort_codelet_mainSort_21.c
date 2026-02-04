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
    // Variant 1: Memory Access Pattern Modification - Use strided access with indirect indexing via precomputed offsets
    // Instead of directly accessing ftab with complex index expressions, precompute base indices and use a stride of 256
    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        Int32 base_vv = ((vv + 1) << 8);
        Int32 base_vv_start = (vv << 8);
        Int32 freq_vv = ftab[base_vv] - ftab[base_vv_start];

        j = i;
        Int32 k = j - h;

        for (; k > (h - 1); k -= h) {
            Int32 candidate = runningOrder[k];
            Int32 base_candidate_end = ((candidate + 1) << 8);
            Int32 base_candidate_start = (candidate << 8);
            Int32 freq_candidate = ftab[base_candidate_end] - ftab[base_candidate_start];

            if (freq_candidate <= freq_vv) break;

            runningOrder[j] = candidate;
            j = k;
        }

        runningOrder[j] = vv;
    }
}
