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
    // Simulate indirect access by creating a virtual stride through alternating indices
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++)
        indices[i] = i;  // Identity mapping for indirect access

    i = 0;
    for (; i < len; i++) {
        size_t idx = indices[i];
        if (idx >= len || !s[idx])
            break;
    }
    free(indices);
    // Ensure i reflects the correct offset in the original string
    for (i = 0; i < len && s[i]; i++)
        ;
}
