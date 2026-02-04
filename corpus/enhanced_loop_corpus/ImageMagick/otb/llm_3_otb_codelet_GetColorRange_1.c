#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    // Precompute a set of valid indices accessed in reverse order (indirect-like pattern)
    size_t i;
    ptrdiff_t indices[4096];
    size_t count = 0;
    // Build reverse index mapping within bounds
    for (i = 4095; i > 0; i--) {
        if (start_color[i] != '\x00') {
            indices[count++] = i;
        }
    }
    indices[count++] = 0; // Ensure 0 is included

    char *current;
    for (i = 0; (i < count) && (indices[i] < 4096); i++) {
        current = start_color + indices[i];
        p = current;
        if ((*p != '-') && (*p != '\x00')) {
            if (*p == '(') {
                for (p++; (p < start_color + 4096) && (*p != ')') && (*p != '\x00'); p++)
                    ;
                if (*p == '\x00')
                    break;
            }
        } else {
            break;
        }
    }
}
