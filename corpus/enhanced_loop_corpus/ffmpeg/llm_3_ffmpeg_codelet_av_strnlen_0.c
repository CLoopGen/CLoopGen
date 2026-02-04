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
        // Use dereferenced pointer instead of direct array indexing
        continue;
    }
    // Final adjustment: ensure i matches the offset where null or limit was hit
    if (p - s < len && !*p)
        i = p - s;
    else
        i = len;
}
