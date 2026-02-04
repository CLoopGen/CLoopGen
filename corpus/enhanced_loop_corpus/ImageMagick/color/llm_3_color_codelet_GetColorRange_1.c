#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated using pointer arithmetic)
    // Instead of direct traversal, we use a precomputed "indirection" table that maps iteration steps.
    // Since we cannot allocate memory, we simulate indirect access using modulo-based indexing.
    size_t i;
    size_t stride = 3; // Simulate non-unit stride through indirection
    size_t offset;
    size_t max_len = 4096;

    for (i = 0; i < max_len; i++) {
        offset = (i * stride) % 4096; // Strided indirect access pattern
        p = start_color + offset;

        if (*p == '\x00') break;
        if (*p == '-') break;

        if (*p == '(') {
            p++;
            while ((*p != ')') && (*p != '\x00')) {
                p++;
            }
            if (*p == '\x00') break;
        }
    }
    // Final adjustment: ensure p ends at correct position as original
    p = start_color + ((i * stride) % 4096);
}
