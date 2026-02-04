#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    // We create a local index map that accesses every other element in reverse order within blocks
    ptrdiff_t i;
    ptrdiff_t len = 0;
    char *temp = start_color;

    // Compute effective length up to terminator or '-'
    while ((len < 4096) && (temp[len] != '-') && (temp[len] != '\x00')) {
        len++;
    }

    // Process indices in chunks using indirect pattern: block-wise reversed access
    for (i = 0; i < len; i++) {
        ptrdiff_t block_start = (i / 8) * 8;
        ptrdiff_t block_offset = 7 - (i % 8); // Reverse within 8-byte blocks
        ptrdiff_t j = block_start + block_offset;
        if (j >= len) continue;

        p = start_color + j;

        if (*p == '(') {
            for (p++; (p < start_color + 4096) && (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
    // Ensure p ends at a valid position
    if (p >= start_color + 4096 || *p == '\x00' || *p == '-')
        p = start_color + (len > 0 ? len - 1 : 0);
}
