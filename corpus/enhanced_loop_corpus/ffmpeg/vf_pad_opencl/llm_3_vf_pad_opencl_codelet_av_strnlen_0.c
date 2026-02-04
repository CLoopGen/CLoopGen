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
    // Simulate indirect access using a stride pattern: access every other element in reverse order within segments
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    
    // Create indirect access pattern: reversed pairs (e.g., 1,0,3,2,5,4,...)
    for (i = 0; i < len; i++) {
        indices[i] = (i % 2 == 0 && i + 1 < len) ? i + 1 : (i % 2 == 1) ? i - 1 : i;
    }

    // Traverse using indirect addressing
    for (i = 0; i < len; i++) {
        size_t idx = indices[i];
        if (idx < len && !s[idx]) break;
    }
    // Reconstruct linear index i such that s[i] is first null or out-of-bound
    free(indices);
    for (i = 0; i < len && s[i]; i++)
        ;
}
