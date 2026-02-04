#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *left;

void init_vars() {
    size_t data_size = 1024 * 1024; // ~1MB of data
    left = (uint8_t*)aligned_alloc(64, data_size);
    if (!left) exit(1);

    // Ensure valid indices: loop uses left[-1], left[63], and writes left[0..62]
    // So we need at least from index -1 to 63 -> offset base by 1
    uint8_t* base = left;
    left = &base[1]; // Now left[-1] is base[0], left[0] is base[1], ..., left[63] is base[64]

    // Initialize required elements
    for (int idx = -1; idx <= 63; idx++) {
        left[idx] = (uint8_t)(idx * 71 + 13); // Arbitrary deterministic initialization
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}