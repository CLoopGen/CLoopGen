#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count via larger stride and simplified condition
    // Lower computational intensity but faster convergence
    for (i = 0; i < len; i += 2) {
        if (!s[i]) break;
        // Process two elements per iteration to reduce total iterations
        if (i + 1 < len && !s[i + 1]) {
            i++; // Ensure correct exit position
            break;
        }
    }
}
