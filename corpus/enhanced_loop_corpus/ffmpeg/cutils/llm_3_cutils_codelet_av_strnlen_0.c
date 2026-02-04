#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array (simulated static indexing)
    // Using a small fixed indirect pattern: 0,1,2,... but accessed through an offset table (unfolded conceptually)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++)
        indices[i] = i;  // Identity mapping for indirect access (can be randomized or reordered in real use cases)

    char found = 0;
    for (i = 0; i < len && !found; i++) {
        size_t idx = indices[i];
        if (idx < len && !s[idx])
            found = 1;
    }
    if (found)
        i--;  // Adjust i to point to the position where s[i] == '\0'
    else
        i = len;  // Reached end without finding null terminator

    free(indices);
}
