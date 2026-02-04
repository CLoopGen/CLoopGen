#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with fixed stride mapping)
    // Instead of direct pointer progression, use an auxiliary index array to dictate access order.
    // Here we simulate indirect access using a precomputed strided index pattern (e.g., pseudo-random-like small jumps).
    static const unsigned char indices[] = {0, 3, 1, 4, 2, 5, 7, 6, 8}; // Small repeating indirect pattern
    size_t idx_len = sizeof(indices) / sizeof(indices[0]);
    size_t seq_idx = 0;
    ptrdiff_t offset = 0;

    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }

        // Apply indirect step: advance using pattern instead of +1
        offset += indices[seq_idx];
        seq_idx = (seq_idx + 1) % idx_len;

        // Bound check to avoid overflow
        if (offset >= 4096)
            break;
        p = start_color + offset;

        // Ensure p stays within valid range
        if (p >= start_color + 4096)
            break;
    }
}
