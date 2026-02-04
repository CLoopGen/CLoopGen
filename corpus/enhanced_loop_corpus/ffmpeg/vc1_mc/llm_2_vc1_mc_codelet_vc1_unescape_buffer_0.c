#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (stride of 2) with forward traversal
    // We process elements in strides, but maintain correctness by adjusting index mapping
    int stride = 2;
    int limit = size - (size % stride); // Make sure we don't go out of bounds
    dsize = 0; // Reset destination size

    for (i = 0; i < limit; i += stride) {
        uint8_t *current = src + i;

        // First element in stride
        if (current[0] == 3 && i >= 2 && !current[-1] && !current[-2] && i < size - 1 && current[1] < 4) {
            dst[dsize++] = current[1];
            // Skip next source byte due to compression-like behavior
            if (i + 1 < size) {
                i++; // Compensate in loop logic
            }
        } else {
            dst[dsize++] = current[0];
        }

        // Second element in stride (if within bounds)
        if (i + 1 < size) {
            uint8_t *next = current + 1;
            if (next[0] == 3 && (i+1) >= 2 && !next[-1] && !next[-2] && (i+1) < size - 1 && next[1] < 4) {
                dst[dsize++] = next[1];
                i++; // Skip the next input as well
            } else {
                dst[dsize++] = next[0];
            }
        }
    }

    // Handle leftover element if size is odd
    if (limit < size) {
        uint8_t *last = src + limit;
        if (last[0] == 3 && limit >= 2 && !last[-1] && !last[-2] && limit < size - 1 && last[1] < 4) {
            dst[dsize++] = last[1];
        } else {
            dst[dsize++] = *last;
        }
    }
}
