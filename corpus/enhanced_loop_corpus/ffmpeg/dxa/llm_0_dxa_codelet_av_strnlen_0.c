#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && s[i]; i++) {
        // Outer loop body is now nested with an inner no-op loop
        for (size_t j = 0; j < 1; j++) {
            // Artificial nesting: adds depth without changing logic
        }
    }
}
