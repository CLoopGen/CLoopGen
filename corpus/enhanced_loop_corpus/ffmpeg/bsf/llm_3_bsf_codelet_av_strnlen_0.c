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
        // Use indirect access through pointer instead of direct array indexing
        continue;
    }
    // Adjust i to reflect correct count if loop exited due to *p == '\0'
    if (i > len) i = len;
}
