#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated using pointer arithmetic as index lookup)
    // Simulate indirect traversal using a precomputed stride pattern (every other element, then reverse condition check)
    ptrdiff_t offset = 0;
    const ptrdiff_t max_len = 4096;
    for (offset = 0; offset < max_len; offset++) {
        char *current = start_color + offset; // Indirect-like access via computed address
        if ((*current == '-') || (*current == '\x00'))
            break;

        if (*current == '(') {
            current++;
            while ((*current != ')') && (*current != '\x00')) {
                offset++; // Keep offset in sync
                current++;
            }
            if (*current == '\x00') {
                p = current;
                return;
            }
        }
    }
    p = start_color + offset; // Update global pointer
}
