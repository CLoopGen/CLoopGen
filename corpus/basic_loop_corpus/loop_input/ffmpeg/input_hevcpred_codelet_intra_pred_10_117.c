#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int size;
uint16_t *left;
uint16_t *filtered_left;

void init_vars() {
    size = 65536; // Adjusted for ~0.01s runtime on typical hardware

    left = (uint16_t*)aligned_alloc(32, (size + 2) * sizeof(uint16_t));
    filtered_left = (uint16_t*)aligned_alloc(32, (size + 2) * sizeof(uint16_t));

    for (int idx = 0; idx < size + 2; idx++) {
        left[idx] = rand() & 0xFFFF;
    }

    i = 2 * size - 2;

    // Ensure loop bounds are valid: i >= 0, and accesses left[i+1], left[i], left[i-1]
    // So we require i-1 >= 0 => i >= 1, but loop runs while i >= 0
    // Therefore, minimum index accessed is i-1 = -1 when i=0 -> unsafe
    // Adjust so that loop starts at min(2*size-2, size+0) and ensure left array covers [i-1, i+1] for all i in [0, 2*size-2]
    // Our allocation already includes extra padding: indices from 0 to size+1, but loop uses up to i+1 where i can be 2*size-2
    // That would access index (2*size-1), which is out of bounds.

    // Correction: the loop index i goes from 2*size-2 down to 0.
    // It accesses: left[i+1], left[i], left[i-1]
    // Max index: i+1 = (2*size-2)+1 = 2*size-1
    // Min index: i-1 = 0-1 = -1 → invalid

    // To prevent out-of-bounds, we must shift indexing or adjust data layout.
    // Instead, reallocate with sufficient padding on both ends.

    free(left);
    free(filtered_left);

    // Pad left by at least 1 on the left and enough on the right
    size_t total_size = 2 * size + 2; // Covers indices from -1 to 2*size
    left = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    filtered_left = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));

    // Now map logical index i to physical index i+1 (so -1 → 0, 0 → 1, ..., 2*size-1 → 2*size)
    for (int idx = -1; idx <= 2*size-1; idx++) {
        left[idx + 1] = rand() & 0xFFFF;
    }
}