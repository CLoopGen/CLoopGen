#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < len; i++) {
        indices[i] = i; // Populate linear index mapping
    }
    char *ptr = s;
    for (i = 0; i < len; i++) {
        if (!ptr[indices[i]]) break;
    }
    free(indices);
}
