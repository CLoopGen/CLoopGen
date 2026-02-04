#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer arithmetic with intermediate pointer
    char *p = s;
    for (i = 0; i < len && *p; i++, p++) {
        // Directly use pointer dereference instead of array indexing
        continue;
    }
    // Update i to reflect actual number of iterations if loop ended early
    if (i >= len || *p == '\0') {
        i = (size_t)(p - s); // Compute final offset
    }
}
