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
            // Dummy operation to ensure use of s[i]
            i++; // Compensate so we don't skip too much after loop increment
            if (i >= len || !s[i]) break;
        }
    }
    // Adjust i back if overshot due to internal increment
    if (i > len) i = len;
}
