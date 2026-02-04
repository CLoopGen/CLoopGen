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
        // Perform dummy access to maintain logic consistency
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index to reflect original termination behavior
            break;
        }
    }
    // Correct final index if exited early due to s[i] == 0
    if (i >= len || !s[i]) {
        // Ensure i points to the first null or out-of-bounds position
        for (; i < len && s[i]; i++);
    }
}
