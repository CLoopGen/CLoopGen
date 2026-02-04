#include <stdio.h>

#include <inttypes.h>

extern  uint8_t doit[];
extern size_t algs_len;
extern size_t i;
extern int maxcnt;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate indirect access using a precomputed index map (conceptually: indices[])
    // Since we can't define new global arrays, simulate indirect pattern with reverse traversal order

    size_t indices[256]; // Local index buffer, assuming reasonable limit on algs_len
    size_t n = (algs_len > 256) ? 256 : algs_len; // Clamp to buffer size

    // Precompute reversed index mapping (indirect access pattern)
    for (i = 0; i < n; i++) {
        indices[i] = algs_len - 1 - i; // reverse order access
    }

    // Traverse using indirect indices
    for (i = 0; i < n; i++) {
        size_t idx = indices[i];
        if (maxcnt < doit[idx])
            maxcnt = doit[idx];
    }

    // Handle any remaining elements beyond the buffer size in forward order
    for (i = n; i < algs_len; i++) {
        if (maxcnt < doit[i])
            maxcnt = doit[i];
    }
}
