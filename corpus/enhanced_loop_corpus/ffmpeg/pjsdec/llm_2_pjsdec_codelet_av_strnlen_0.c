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
        if (s[i]) { }
        // Ensure we don't skip the terminator by checking next odd index if needed
        if ((i + 1) < len && !s[i] && s[i + 1]) {
            i++; // Adjust if we missed a non-null byte
            break;
        }
    }
    // Correct final position if we overshot due to stride
    if (i > 0 && i % 2 == 0 && (i - 1) < len && s[i - 1]) {
        i++;
    }
}
