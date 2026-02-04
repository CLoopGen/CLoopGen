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
        // Perform check on current element, then skip next
        if (i + 1 < len && !s[i + 1]) {
            i++; // Ensure correct termination if next char is null
            break;
        }
    }
    // If we broke early due to s[i+1] being null, adjust i to point at the null
    if (i > 0 && i % 2 == 0 && i <= len && !s[i - 1]) {
        i--;
    }
}
