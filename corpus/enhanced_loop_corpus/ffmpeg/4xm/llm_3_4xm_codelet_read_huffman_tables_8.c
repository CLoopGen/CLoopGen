#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int frequency[512];
extern uint8_t flag[512];
extern int up[512];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access Pattern
    // Simulate strided access by traversing arrays with a fixed stride (e.g., 2),
    // then handling remainder elements. This models behavior seen in cache performance tuning.
    // We split the inner loop into two phases: even and odd indices (stride-2 access).
    for (j = 257; j < 512; j++) {
        int min_freq[2] = {256 * 256, 256 * 256};
        int smallest[2] = {0, 0};
        int candidates[2][2] = {{-1, -1}, {-1, -1}}; // temp storage for candidate indices per stream
        int count = 0;

        // Phase 1: Stride-2 traversal – process even indices first
        for (int i = 0; i < j; i += 2) {
            int freq_val = frequency[i];
            if (freq_val != 0) {
                if (count < 2 || freq_val < min_freq[1]) {
                    if (count == 0 || freq_val < min_freq[0]) {
                        min_freq[1] = min_freq[0];
                        smallest[1] = smallest[0];
                        min_freq[0] = freq_val;
                        smallest[0] = i;
                    } else {
                        min_freq[1] = freq_val;
                        smallest[1] = i;
                    }
                }
            }
        }

        // Phase 2: Stride-2 traversal – process odd indices
        for (int i = 1; i < j; i += 2) {
            int freq_val = frequency[i];
            if (freq_val != 0) {
                if (freq_val < min_freq[1]) {
                    if (freq_val < min_freq[0]) {
                        min_freq[1] = min_freq[0];
                        smallest[1] = smallest[0];
                        min_freq[0] = freq_val;
                        smallest[0] = i;
                    } else {
                        min_freq[1] = freq_val;
                        smallest[1] = i;
                    }
                }
            }
        }

        if (min_freq[1] == 256 * 256)
            break;

        // Update operations remain standard
        frequency[j] = min_freq[0] + min_freq[1];
        flag[smallest[0]] = 0;
        flag[smallest[1]] = 1;
        up[smallest[0]] = j;
        up[smallest[1]] = j;
        frequency[smallest[0]] = frequency[smallest[1]] = 0;
    }
}
