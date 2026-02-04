#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (Gather) Access via Index Array
    // Simulate indirect access using a precomputed index map
    int *indices = (int*)malloc(size * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create an indirect access pattern: reverse order access
    for (int j = 0; j < size; j++) {
        indices[j] = size - 1 - j; // Reverse indexing
    }

    dsize = 0;
    for (i = 0; i < size; i++) {
        int idx = indices[i]; // Indirect access index
        uint8_t *p = src + idx;

        // Apply same logic but based on reversed access
        if (p[0] == 3 && idx >= 2 && !p[-1] && !p[-2] && idx < size - 1 && p[1] < 4) {
            dst[dsize++] = p[1];
            // Skip next logical element (simulate double consume)
            if (i + 1 < size) {
                i++;
            }
        } else {
            dst[dsize++] = *p;
        }
    }

    free(indices);
}
