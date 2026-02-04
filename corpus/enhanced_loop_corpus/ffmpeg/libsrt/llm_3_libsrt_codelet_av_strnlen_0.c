#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with offset array
    size_t *indices = (size_t*)malloc(sizeof(size_t) * (len + 1));
    if (!indices) return; // Handle allocation failure
    for (size_t temp_i = 0; temp_i <= len; temp_i++) {
        indices[temp_i] = temp_i; // Populate index map
    }
    for (i = 0; i < len && s[indices[i]]; i++)
        ;
    free(indices);
}
