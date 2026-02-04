#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Transform original loop into a doubly nested structure with split condition
    // Simulating deeper nesting while preserving termination behavior
    for (i = 0; i < len; i++) {
        if (!s[i]) break;
        for (size_t j = 0; j < 1; j++) {
            // Artificial nesting: inner loop performs no operation but maintains depth
        }
    }
}
