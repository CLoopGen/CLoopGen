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
    // Simulate indirect access pattern using a fixed offset sequence (every other element)
    size_t indices[256];
    size_t count = 0;
    for (size_t j = 0; j < len && count < 256; j++) {
        indices[count++] = j; // Store sequential indices (can be randomized or strided in real use)
    }
    for (i = 0; i < count && indices[i] < len && s[indices[i]]; i++)
        ;
    // Final assignment to match original semantics: i is index of first null or out-of-bound
    if (i < count && indices[i] < len)
        i = indices[i];
    else
        i = len;
}
