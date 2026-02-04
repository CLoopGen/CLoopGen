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
    // Using a virtual "indirection" through an offset sequence without extra storage
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < len; i++) {
        indices[i] = i; // Identity mapping as base for indirect access
    }
    for (i = 0; i < len; i++) {
        size_t idx = indices[i]; // Indirect access
        if (idx >= len || !s[idx]) {
            i = idx; // Adjust output i to reflect actual position
            break;
        }
    }
    free(indices);
}
