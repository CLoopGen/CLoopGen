#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access pattern using an index array to simulate irregular memory access
    // Simulate indirect indexing via a lookup table (declared as static to avoid dynamic allocation)
    static int indices[256];
    for (int j = 0; j < 256; ++j) {
        indices[j] = j * 3 + 1; // Populate with non-consecutive, non-regular sequence
    }

    int idx = 0;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        // Use indirect index to influence behavior (simulating data-dependent access)
        uint32_t stride = indices[idx % 256];
        re_cache <<= (1);
        re_index += (stride);  // Indirect influence on re_index
        idx++;
    }
}
