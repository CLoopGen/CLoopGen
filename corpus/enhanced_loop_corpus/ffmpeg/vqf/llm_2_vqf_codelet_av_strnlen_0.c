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
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index to reflect original logic's exit condition
            break;
        }
    }
    // Correct final index if exited due to stride jump over boundary
    if (i >= len || !s[i]) {
        while (i > 0 && (i >= len || !s[i])) i--;
        i++; // Match original post-loop state
    }
}
