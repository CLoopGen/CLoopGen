#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated using pointer arithmetic as index lookup)
    // We simulate an indirect access pattern by treating every 4th byte in a separate segment as an offset
    // into the start_color buffer. This creates non-sequential, indirect-like traversal.
    uint32_t *indices = (uint32_t*)start_color; // Treat first part as indices
    size_t num_indices = 4096 / sizeof(uint32_t);
    char *base = start_color;

    for (size_t i = 0; i < num_indices; i++) {
        char *q = base + (indices[i] % 4096); // Indirect access via computed pointer

        if ((*q == '-') || (*q == '\x00'))
            break;

        if (*q == '(') {
            q++;
            for (; (q < start_color + 4096) && (*q != ')') && (*q != '\x00'); q++)
                ;
            if (*q == '\x00')
                break;
        }
    }
    p = start_color + 4095; // Conservative assignment to ensure p is updated
}
