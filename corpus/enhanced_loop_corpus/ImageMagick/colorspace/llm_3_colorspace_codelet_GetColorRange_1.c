#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Instead of directly traversing `start_color`, we use an auxiliary index mapping
    // to simulate indirect access. For realism, we generate indices on-the-fly without extra storage.
    size_t i = 0;
    size_t indices[4096]; // Simulate precomputed access pattern (e.g., reordered or transformed)
    for (size_t addr = 0; addr < 4096 && start_color[addr] != '\x00'; addr++) {
        indices[i++] = addr;
    }
    p = start_color;
    for (size_t j = 0; j < i; j++) {
        char *current = &start_color[indices[j]];
        if (*current == '(') {
            current++;
            while (*current != ')' && *current != '\x00') {
                current++;
            }
            if (*current == '\x00') {
                p = current;
                break;
            }
        } else if (*current == '-' || *(current + 1) == '\x00') {
            p = current;
            break;
        }
        if (j + 1 < i) {
            p = &start_color[indices[j + 1]]; // Update p to next indirect location
        }
    }
}
