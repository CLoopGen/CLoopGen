#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated using pointer arithmetic)
    // Create a virtual "index map" by precomputing valid indices within the range
    ptrdiff_t len = 0;
    char *ptr = start_color;
    while (ptr[len] != '\x00' && ptr[len] != '-' && len < 4095) len++;

    // Simulate indirect access using a fixed offset sequence (e.g., reverse order)
    for (ptrdiff_t i = 0; i <= len; i++) {
        p = &start_color[i];  // Forward indirect indexing (could be shuffled or strided)

        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }

        // Early termination check based on original condition
        if (*p == '-' || *p == '\x00')
            break;
    }
}
