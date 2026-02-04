#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated with offset indexing)
    // Create an indirect access pattern by iterating through indices in a shuffled-like order
    // Here, we simulate indirect access using a virtual "index map" accessed in reverse every other step
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure

    for (i = 0; i < len; i++) {
        indices[i] = i;
    }

    // Access pattern: even steps forward, odd steps backward (zig-zag)
    for (i = 0; i < len;) {
        size_t idx = indices[i];
        if (!s[idx]) break;

        if ((i & 1) == 0 && (i + 1) < len) {
            i += 1; // Forward step
        } else if ((i & 1) == 1) {
            i += 1; // Alternate logic still moves forward in index scan but uses indirect access
        } else {
            i += 1;
        }
    }

    // Finalize i to match original semantics: position of first null or len
    for (i = 0; i < len && s[i]; i++)
        ;

    free(indices);
}
