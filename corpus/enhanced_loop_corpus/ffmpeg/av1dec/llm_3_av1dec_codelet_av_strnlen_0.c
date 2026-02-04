#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic)
    // Use a synthetic stride table for indirect pattern (e.g., access every other byte in reverse trend)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Build indirect access pattern: descending even indices
    size_t count = 0;
    for (size_t j = (len - 1) | 1; j > 0; j -= 2) {
        if (j < len) indices[count++] = j;
    }

    // Traverse using indirect addressing
    i = 0;
    for (size_t idx = 0; idx < count; idx++) {
        size_t pos = indices[idx];
        if (pos < len && !s[pos]) {
            i = pos;
            free(indices);
            return;
        }
        i = (pos < len) ? (pos + 1) : i;
    }

    // Final forward scan from last known position
    for (; i < len && s[i]; i++)
        ;

    free(indices);
}
