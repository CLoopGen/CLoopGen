#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Precompute indices as if traversing non-sequentially (e.g., reverse every 8 elements)
    ptrdiff_t i;
    ptrdiff_t len = 0;
    char *temp = start_color;
    // First, compute effective length up to terminator or '-'
    while (len < 4096 && temp[len] != '-' && temp[len] != '\x00') {
        len++;
    }

    // Traverse using indirect access: reverse blocks of 8 for strided pattern
    for (i = 0; i < len; i++) {
        ptrdiff_t block_base = (i / 8) * 8;
        ptrdiff_t offset_in_block = i % 8;
        ptrdiff_t reversed_index = block_base + (7 - offset_in_block); // Reverse within 8-byte block
        if (reversed_index >= len) continue;

        p = start_color + reversed_index;

        if (*p == '(') {
            for (p++; (p < start_color + 4096) && (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00')
                break;
        }
    }
    // Ensure p ends at a valid position
    if (p > start_color + 4095) p = start_color + 4095;
}
