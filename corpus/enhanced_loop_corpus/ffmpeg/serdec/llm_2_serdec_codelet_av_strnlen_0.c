#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform dummy access to maintain semantic consistency
        // Actual termination still depends on s[i] being non-null
        if (i + 1 < len && s[i + 1]) {
            // Dummy block to ensure compiler doesn't optimize away
        }
    }
    // Adjust final index to point to first null or beyond len
    for (; i < len && s[i]; i++)
        ;
}
