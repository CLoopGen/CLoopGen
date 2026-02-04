#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t a;
extern uint64_t ret;
extern uint64_t ret_sq;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Memory Access Pattern Modification using consecutive precomputation
    // Precompute potential values in a consecutive memory layout (array), then iterate
    // through the array in reverse order to simulate a different access pattern.
    uint64_t candidates[32];
    int i = 0;
    for (int t = 31; t >= 0; t--) {
        uint64_t b = ret_sq + (1ULL << (t * 2)) + (ret << t) * 2;
        candidates[i++] = b;
    }
    // Now traverse precomputed values consecutively in original order
    for (i = 0; i < 32; i++) {
        int t = 31 - i;  // recover original s value
        uint64_t b = candidates[i];
        if (b <= a) {
            ret_sq = b;
            ret += 1ULL << t;
        }
    }
}
