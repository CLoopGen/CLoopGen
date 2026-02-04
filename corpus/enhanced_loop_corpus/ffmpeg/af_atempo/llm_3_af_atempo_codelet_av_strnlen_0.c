#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated using offset indexing)
    // Create an indirect access pattern by iterating through indices stored in a virtual "table"
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = i; // populate index map
    }
    // Now traverse the string indirectly
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx]) {
            // Adjust original `i` to reflect the current logical position in the string
            i = idx;
            break;
        }
    }
    free(indices);
}
