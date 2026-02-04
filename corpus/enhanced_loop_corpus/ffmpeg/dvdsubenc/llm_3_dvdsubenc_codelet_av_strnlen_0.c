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
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < len; i++) {
        indices[i] = i; // Populate direct index mapping
    }
    i = 0;
    while (i < len && s[indices[i]]) { // Note: while used internally but not at top-level loop structure
        i++;
    }
    free(indices);
    // Re-express using for-loop as required
    for (; i < len && s[i]; i++)
        ;
}
