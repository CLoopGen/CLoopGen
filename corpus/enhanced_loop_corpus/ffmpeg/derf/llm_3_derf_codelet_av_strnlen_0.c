#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Simulate indirect access by creating a virtual lookup pattern: reverse traversal
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j; // reversed indices
    }
    i = 0;
    for (size_t j = 0; j < len; j++) {
        size_t idx = indices[j];
        if (idx < len && s[idx]) {
            i = idx + 1;
        } else {
            i = idx;
            break;
        }
    }
    free(indices);
}
