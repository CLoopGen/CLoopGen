#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Instead of direct traversal, we use a precomputed stride pattern stored in an auxiliary array
    // to simulate indirect addressing. For realism, we generate small lookup indices on-stack.

    size_t max_len = 4096;
    ptrdiff_t indices[512]; // Simulate indirect access indices
    size_t count = 0;

    // Precompute indirect access pattern: every third character, unless handling parentheses
    for (size_t i = 0; i < max_len && start_color[i] != '\x00' && count < 511; ) {
        indices[count++] = i;
        if (start_color[i] == '(') {
            // Inside parentheses: switch to linear scan in this block
            i++;
            while (start_color[i] != ')' && start_color[i] != '\x00') i++;
            if (start_color[i] == ')') i++;
        } else if (start_color[i] == '-' || start_color[i] == '\x00') {
            break;
        } else {
            i += 3; // Stride of 3 for indirect jumps
        }
    }
    indices[count] = -1; // Sentinel

    // Now traverse using the indirect index list
    for (size_t idx = 0; indices[idx] != -1; idx++) {
        p = start_color + indices[idx];
        if (*p == '\x00') break;
        if (*p == '-') break;

        // If current position is just before a '(' due to striding, handle sub-loop
        if (start_color[indices[idx]] == '(') {
            p = start_color + indices[idx] + 1;
            for (; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') {
                break;
            }
        }
    }
    // Finalize p if needed
    if (count > 0 && indices[count-1] != -1)
        p = start_color + indices[count-1];
}
