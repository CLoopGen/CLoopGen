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
    // Create a local pointer to simulate indirect traversal through an index map
    const char *ptr = s;
    size_t idx = 0;
    for (i = 0; (idx = i) < len && ptr[idx]; i++) {
        // Use indirect indexing (via computed idx) to access s
        // This mimics potential table-based or scatter-like access patterns
        ;
    }
}
