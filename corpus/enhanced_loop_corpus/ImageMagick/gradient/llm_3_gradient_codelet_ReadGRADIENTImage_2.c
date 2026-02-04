#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Instead of direct traversal, we use a virtual "index map" accessed indirectly.
    // Here, we simulate indirect access by using an offset table conceptually,
    // but since we can't introduce large auxiliary data, we emulate stride-varying indirect jumps.

    char *base = start_color;
    size_t idx = 0;
    size_t jump_table[3] = {1, 2, 1};  // Simulated irregular access pattern

    for (p = base; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            p++;
            for (; (*p != ')') && (*p != '\x00'); ) {
                // Use indirect-like progression: cycle through jump_table
                p += jump_table[idx % 3];
                idx++;
                // Safety check after each strided jump
                if (*(p - 1) == ')') {
                    p--; // Adjust if we overshot
                    break;
                }
                if (*p == '\x00') {
                    break;
                }
            }
            if (*p == '\x00') break;
        }

        // Advance using indirect indexing pattern
        p += jump_table[idx % 3];
        idx++;
    }
}
