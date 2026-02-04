#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate step
    char *p = s;
    size_t j = 0;
    for (i = 0; j < len && *(p + j); j++) {
        i = j; // Track progress in original index
        // Use indirect offset calculation
        if (*(p + j + 0) == 0) break;
    }
    // Final adjustment to match original semantics exactly
    i = j;
}
