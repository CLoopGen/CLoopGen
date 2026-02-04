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
    // Simulate indirect access by treating 'len' elements of a separate index map as access pattern
    // Since we cannot introduce new global state, simulate stride-like indirect pattern using modulo
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    // Create an indirect access pattern: reverse order traversal
    for (size_t j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }

    i = 0;
    for (size_t idx = 0; idx < len; idx++) {
        size_t pos = indices[idx];
        if (!s[pos]) {
            i = len - idx; // Set 'i' to position in original forward scan where null was found
            break;
        }
        i = len - idx; // Update i as if scanning forward
    }

    free(indices);
}
