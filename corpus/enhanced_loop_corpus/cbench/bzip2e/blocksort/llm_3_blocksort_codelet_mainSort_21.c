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



void loop(){
    // Use strided memory access pattern: precompute base offsets to simulate stride over ftab
    // and restructure inner logic using a counted loop approximation

    UInt32 *ftab_base = ftab;
    Int32 stride = 1 << 8; // Precomputed shift scale factor

    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        j = i;

        Int32 current_diff = ftab_base[(vv + 1) * 256] - ftab_base[vv * 256]; // Strided access by 256
        Int32 k;

        // Replace original while with bounded for-loop limiting steps based on possible h-gaps
        // Simulate up to max possible shifts in reverse direction
        for (k = 0; k < (i / h); k++) {
            Int32 idx = j - h;
            Int32 candidate = runningOrder[idx];
            Int32 candidate_diff = ftab_base[(candidate + 1) * 256] - ftab_base[candidate * 256];

            if (candidate_diff <= current_diff) break;

            runningOrder[j] = candidate;
            j = idx;
        }

        runningOrder[j] = vv;
    }
}
