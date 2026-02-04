#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an array of indices (simulated via pointer arithmetic)
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (size_t j = 0; j < len; j++)
        indices[j] = j;
    for (i = 0; i < len && s[indices[i]]; i++)
        ;
    free(indices);
}
