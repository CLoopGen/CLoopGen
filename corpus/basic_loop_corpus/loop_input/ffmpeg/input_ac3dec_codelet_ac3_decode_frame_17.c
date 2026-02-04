#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
int buf_size;
int i;

void init_vars() {
    buf_size = 16777216; // 16MB buffer to ensure ~0.01s runtime on modern CPUs
    buf = (uint8_t*)aligned_alloc(32, buf_size);
    if (!buf) exit(1);

    // Initialize buffer with safe values to avoid out-of-bounds access
    // Ensure that accesses to i-1 and i+1 are valid within loop bounds
    for (int j = 0; j < buf_size; j++) {
        buf[j] = (uint8_t)(j % 256);
    }

    // Set known initial state for deterministic behavior
    i = 1;

    // Ensure at least one position triggers the first condition but avoids premature break
    // Place pattern so that when i is near end, we don't go out of bounds in buf[i+1]
    int trigger_index = buf_size - 4;
    if (trigger_index % 2 == 0) trigger_index--;

    if (trigger_index >= 3) {
        buf[trigger_index] = 119;
        buf[trigger_index - 1] = 11;
        buf[trigger_index + 1] = 11; // So (buf[i] ^ buf[i+1]) != (119^11)
    }
}