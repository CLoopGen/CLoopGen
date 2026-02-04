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
        // Skip every other character, but still check null terminator
        if (i + 1 < len && s[i + 1]) {
            // Dummy access to maintain data flow
        }
    }
    // Adjust i back to last valid position if needed
    while (i > 0 && (!s[i] || i >= len)) i--;
    i++; // Point to the correct end as in original
}
