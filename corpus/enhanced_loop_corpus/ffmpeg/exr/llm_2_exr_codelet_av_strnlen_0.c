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
            // Dummy operation to ensure usage
            i++; // Compensate so we don't skip logic entirely, still progress
            if (i >= len || !s[i]) break;
        }
    }
    // Adjust i back to correct termination point if overshot
    if (i > len || (i > 0 && !s[i-1])) i--;
}
