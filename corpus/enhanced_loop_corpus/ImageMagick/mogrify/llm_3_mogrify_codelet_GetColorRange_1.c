#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated with pointer arithmetic)
    // Create a local index map for indirect traversal (every 3rd element)
    ptrdiff_t i;
    ptrdiff_t indices[1365]; // ~4096 / 3, enough to cover range
    for (i = 0; i < 1365; i++) {
        indices[i] = i * 3;
        if (i * 3 >= 4096) {
            indices[i] = 4095; // clamp to last valid index
        }
    }

    for (i = 0; (indices[i] < 4096) && (start_color[indices[i]] != '-') && (start_color[indices[i]] != '\x00'); i++) {
        char *q = &start_color[indices[i]];
        if (*q == '(') {
            q++;
            while ((ptrdiff_t)(q - start_color) < 4096 && *q != ')' && *q != '\x00') {
                q++;
            }
            if (*q == '\x00') {
                p = q;
                return;
            }
        }
        p = q;
    }
    p = &start_color[indices[i-1]]; // update p to last accessed location
}
