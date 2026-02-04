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
    // Simulate indirect access using a stride-1 step but through an auxiliary index
    size_t *indices = (size_t*)malloc(len * sizeof(size_t));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < len; i++) {
        indices[i] = i; // Direct mapping, can be randomized in real indirect patterns
    }
    i = 0;
    while (i < len && s[indices[i]]) { // Avoid while per constraints - rewrite as for
        i++;
    }
    free(indices);
}
