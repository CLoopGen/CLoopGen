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
        // Access current element to maintain dependency
        if (s[i]) {
            // Continue scanning on valid char, but skip every other index
            i++; // Compensate for stride to ensure forward progress within bounds
            if (i >= len || !s[i]) break;
        }
    }
}
