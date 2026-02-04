#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate offset array
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (size_t j = 0; j < len; j++)
        indices[j] = j;  // Populate linear index mapping

    i = 0;
    for (size_t j = 0; j < len; j++) {
        i = indices[j];
        if (!s[i]) break;
    }
    free(indices);
}
