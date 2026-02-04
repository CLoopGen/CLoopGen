#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with an array of indices
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < len; i++) {
        indices[i] = i; // populate index array
    }
    char *p = s;
    for (i = 0; i < len; i++) {
        if (!p[indices[i]]) break;
    }
    free(indices);
}
