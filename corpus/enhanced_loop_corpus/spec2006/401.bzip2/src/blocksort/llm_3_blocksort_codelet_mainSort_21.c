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
    // Variant 2: Memory Access Pattern Modification - Consecutive array-like access using auxiliary buffer to simulate reordered reads
    // Simulate consecutive memory access by precomputing frequency differences in a temporary array to improve locality

    Int32 freq[256];
    for (Int32 idx = 0; idx < 256; idx++) {
        freq[idx] = ftab[((idx + 1) << 8)] - ftab[(idx << 8)];
    }

    for (i = h; i <= 255; i++) {
        vv = runningOrder[i];
        Int32 current_freq = freq[vv];
        j = i;

        Int32 pos = j - h;
        for (; pos >= h; pos -= h) {
            Int32 candidate = runningOrder[pos];
            if (freq[candidate] <= current_freq) break;
            runningOrder[j] = candidate;
            j = pos;
        }

        if (!(j <= h - 1)) {
            Int32 candidate = runningOrder[pos];
            if (freq[candidate] > current_freq) {
                runningOrder[j] = candidate;
                j = pos;
            }
        }

        runningOrder[j] = vv;
    }
}
