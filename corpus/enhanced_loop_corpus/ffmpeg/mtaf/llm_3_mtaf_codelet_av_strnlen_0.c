#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Simulate indirect access by precomputing indices in a temporary array
    size_t *indices = malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = i; // Normal sequential order, but allows for future indirection
    }
    for (i = 0; i < len; ) {
        size_t idx = indices[i]; // Indirect access via index array
        if (!s[idx]) break;
        i++;
    }
    free(indices);
}
