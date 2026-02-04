#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulate an indirect access pattern by treating `s` as accessed through a virtual offset list
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++)
        indices[i] = i;  // identity mapping for indirect access

    for (i = 0; i < len && s[indices[i]]; i++)
        ;

    free(indices);
}
