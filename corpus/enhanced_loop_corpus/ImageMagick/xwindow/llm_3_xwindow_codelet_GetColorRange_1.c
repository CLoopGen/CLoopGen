#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (simulated with pointer arithmetic)
    ptrdiff_t index = 0;
    ptrdiff_t indices[4096];
    // Precompute linear indices (could be modified for non-linear patterns)
    for (ptrdiff_t i = 0; i < 4096; i++) {
        indices[i] = i;
    }
    for (index = 0; (start_color[indices[index]] != '-') && (start_color[indices[index]] != '\x00'); index++) {
        p = &start_color[indices[index]];
        if (*p == '(') {
            for (index++; (start_color[indices[index]] != ')') && (start_color[indices[index]] != '\x00'); index++)
                ;
            p = &start_color[indices[index]];
            if (*p == '\x00')
                break;
        }
    }
    // Adjust final p to reflect last accessed location
    if (index < 4096)
        p = &start_color[indices[index]];
}
