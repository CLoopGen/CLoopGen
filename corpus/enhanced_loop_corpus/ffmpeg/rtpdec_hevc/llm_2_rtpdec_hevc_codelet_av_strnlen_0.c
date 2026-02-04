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
        // Perform dummy access to maintain semantic similarity
        if ((i + 1) < len && s[i + 1]) {
            // This branch does not alter control flow but simulates checking next element
        }
    }
    // Fix final index to match original semantics (find first null or out-of-bounds)
    for (; i < len && s[i]; i++)
        ;
}
