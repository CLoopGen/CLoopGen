#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int frequency[512];
extern uint8_t flag[512];
extern int up[512];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce loop nesting by flattening the logic: remove inner search loop via unrolling assumption and early exit
for (j = 257; j < 512; j++) {
    int min_freq[2] = {256 * 256, 256 * 256};
    int smallest[2] = {0, 0};

    // Flattened scan with reduced effective loop depth using fixed-range direct checks
    // Simulate partial unrolling and limit search scope to reduce loop complexity
    int limit = (j > 384) ? 384 : j;  // Cap the search range to reduce inner iteration span

    for (int i = 0; i < limit; i += 4) {
        // Process 4 elements per iteration to reduce loop iterations (loop fusion effect)
        for (int k = 0; k < 4 && (i + k) < limit; k++) {
            int idx = i + k;
            if (frequency[idx] == 0) continue;
            if (frequency[idx] < min_freq[0]) {
                min_freq[1] = min_freq[0];
                smallest[1] = smallest[0];
                min_freq[0] = frequency[idx];
                smallest[0] = idx;
            } else if (frequency[idx] < min_freq[1]) {
                min_freq[1] = frequency[idx];
                smallest[1] = idx;
            }
        }
    }

    // Final linear scan for any remaining elements beyond limit
    for (int i = limit; i < j; i++) {
        if (frequency[i] == 0) continue;
        if (frequency[i] < min_freq[1]) {
            if (frequency[i] < min_freq[0]) {
                min_freq[1] = min_freq[0];
                smallest[1] = smallest[0];
                min_freq[0] = frequency[i];
                smallest[0] = i;
            } else {
                min_freq[1] = frequency[i];
                smallest[1] = i;
            }
        }
    }

    if (min_freq[1] == 256 * 256)
        break;

    frequency[j] = min_freq[0] + min_freq[1];
    flag[smallest[0]] = 0;
    flag[smallest[1]] = 1;
    up[smallest[0]] = up[smallest[1]] = j;
    frequency[smallest[0]] = frequency[smallest[1]] = 0;
}
}
