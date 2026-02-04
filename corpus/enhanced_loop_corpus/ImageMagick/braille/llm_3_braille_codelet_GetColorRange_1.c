#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate indirect access by precomputing valid indices within bounds
    ptrdiff_t i;
    ptrdiff_t indices[4096];
    ptrdiff_t count = 0;
    char *base = start_color;

    // Build indirect access pattern: only even indices
    for (i = 0; i < 4096 && base[i] != '\x00'; i += 2) {
        indices[count++] = i;
    }

    for (i = 0; i < count; i++) {
        p = base + indices[i];
        if (*p == '-' || *p == '\x00') break;
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++) {
                ;
            }
            if (*p == '\x00')
                break;
        }
    }
}
