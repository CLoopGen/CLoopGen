#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array
    // Simulate indirect access using a stride-1 traversal but through an address offset
    char *p = s;
    for (i = 0; i < len && *p; i++, p++) {
        // Direct but pointer-based access — maintains logical equivalence
        // This changes access pattern from indexed to pointer dereference
    }
}
