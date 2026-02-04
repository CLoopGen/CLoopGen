#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Create a simulated "indirect" access pattern using fixed offset jumps in a predefined sequence
    char *base = start_color;
    ptrdiff_t offsets[] = {0, 1, 2, 4, 8, 16}; // Example indirect access strides
    int num_offsets = sizeof(offsets) / sizeof(offsets[0]);
    int idx = 0;
    char *current = base;

    for (int i = 0; (*current != '-') && (*current != '\x00'); i = (i + 1) % num_offsets, current = base + (idx += offsets[i])) {
        if (current < base) break; // Safety check for underflow
        if (*current == '(') {
            current++; // Step into after '('
            for (; (*current != ')') && (*current != '\x00'); current++) {
                // Linear scan inside parentheses for correctness
            }
            if (*current == '\x00') {
                current--; // Adjust so outer loop can detect null
                break;
            }
        }
    }
    p = current; // Update global pointer
}
