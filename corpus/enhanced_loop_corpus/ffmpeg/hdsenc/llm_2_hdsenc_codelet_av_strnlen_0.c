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
        // Access current element to maintain side effect
        if (s[i]) {
            // Continue until null terminator or bounds exceeded
            i++; // Adjust to simulate forward progress
            if (i >= len || !s[i]) break;
        }
    }
    // Ensure i is not beyond valid range
    if (i > len) i = len;
}
