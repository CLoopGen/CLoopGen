#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array, accessed in a reordered pattern
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) {
        for (i = 0; i < len && s[i]; i++);
        return;
    }
    // Create indirect access order (e.g., reverse indexing)
    for (i = 0; i < len; i++) {
        indices[i] = len - 1 - i;
    }
    // Traverse using indirect indices, but simulate forward scan logic
    size_t temp_i = 0;
    for (i = 0; i < len; i++) {
        size_t idx = indices[len - 1 - temp_i]; // Reverse back to original order for correctness
        if (!s[idx] || idx >= len) {
            break;
        }
        temp_i++;
    }
    i = temp_i;
    free(indices);
}
