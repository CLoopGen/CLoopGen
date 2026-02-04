#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with step
    char *p = s;
    for (i = 0; i < len && *p; i++) {
        p = s + i; // Explicit indirect access, could be extended to non-linear patterns
    }
}
