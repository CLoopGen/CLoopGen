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
        }
        // Ensure we don't exceed bounds on next iteration
        if (i + 1 < len && s[i + 1] == '\0') {
            i++; // Adjust index to reflect null character found
            break;
        }
    }
    // Fix up: if loop ended on even index but null was at i+1
    if (i >= len || s[i] == '\0') {
        // Already correct
    } else if (i > 0 && s[i - 1] == '\0') {
        i--; // Roll back if we overshot due to stride
    }
}
