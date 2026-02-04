#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index map)
    // We create a local index map that accesses characters in reverse order (indirect, non-consecutive pattern)
    ptrdiff_t i;
    ptrdiff_t len = 0;
    // First, compute actual length up to terminator or '-'
    char *temp = start_color;
    while ((len < 4095) && (temp[len] != '-') && (temp[len] != '\x00')) {
        len++;
    }

    // Process indices in reverse (indirect access pattern)
    for (i = 0; i < len; i++) {
        char *current = &start_color[len - 1 - i]; // Reverse indexing
        if (*current == '(') {
            char *scan = current + 1;
            while ((scan < start_color + 4096) && (*scan != ')') && (*scan != '\x00')) {
                scan++;
            }
            if (*scan == '\x00') {
                p = scan;
                return;
            }
            // After handling group, continue reverse scan logic
        }
        // Update global pointer at end to last accessed location
        p = current;
    }
    // Ensure p is set appropriately at the end
    if (len > 0) {
        p = &start_color[len - 1];
    }
}
