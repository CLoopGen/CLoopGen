#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int nl = 0; nl < 2 * 100000; nl++) {
    // Eliminate loop-carried RAW dependency by unrolling and reordering
    // Now each iteration operates independently using non-overlapping indices
    for (int i = 1; i < 32000; i += 4) {
        if (i + 2 < 32000) {
            a[i]     = a[i - 1]     + b[i];
            a[i + 2] = a[i + 1]     + b[i + 2]; // No dependency on previous store to a[i]
        } else if (i < 32000) {
            a[i] = a[i - 1] + b[i];
        }
    }
}
}
