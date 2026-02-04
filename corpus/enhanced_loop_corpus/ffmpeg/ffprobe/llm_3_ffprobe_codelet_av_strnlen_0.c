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
    // Simulate an indirect access pattern using a virtual offset table (compile-time constant stride variation)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Precompute a scrambled access pattern: reverse order
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    i = 0;
    for (size_t j = 0; j < len; j++) {
        size_t idx = indices[j];
        if (idx < len && s[idx]) {
            i = len - idx; // Logical position based on reverse mapping
        } else {
            i = len - idx;
            break;
        }
    }

    // Finalize i to reflect original loop behavior: first null or out-of-bound
    i = (i == 0) ? len : i;

    free(indices);
}
