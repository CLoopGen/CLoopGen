#include <stdint.h>
#include <stdlib.h>

int i;
uint16_t *left;

void init_vars() {
    // Allocate a buffer with sufficient size to make the loop take ~0.01 seconds
    // The loop runs 63 iterations, so we need to scale data size accordingly.
    // We'll allocate an array of uint16_t with 2^24 elements (~32MB), which is large enough
    // to cause measurable execution time when accessed repeatedly, but not excessive.

    const size_t total_size = 1 << 24; // 16M elements, ~32MB for uint16_t
    uint16_t *buffer = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!buffer) exit(1);

    // Ensure left[-1] and left[63] are valid: place the working block such that
    // index -1 and 63 are within allocated bounds.
    // So we need at least 65 elements: indices from -1 to 63 inclusive.
    // Place the working segment starting at index 1 in the buffer so that:
    //   left = &buffer[1], then left[-1] = buffer[0], left[63] = buffer[64]
    left = &buffer[1];

    // Initialize boundary values used in computation
    buffer[0] = 1000;     // left[-1]
    buffer[64] = 2000;    // left[63]

    // Initialize other elements if needed (not strictly necessary, but for predictability)
    for (size_t idx = 0; idx < total_size; idx++) {
        if (idx != 0 && idx != 64)
            buffer[idx] = 500 + (idx % 100);
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}