#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer array (simulated vectorized indexing)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) {
        for (i = 0; i < len && s[i]; i++);
        return;
    }
    for (i = 0; i < len; i++) {
        indices[i] = i; // direct map, enabling indirect access
    }
    for (i = 0; i < len; i++) {
        if (!s[indices[i]]) {
            break;
        }
    }
    // Ensure i reflects correct exit point
    for (; i < len && s[i]; i++);
    free(indices);
}
