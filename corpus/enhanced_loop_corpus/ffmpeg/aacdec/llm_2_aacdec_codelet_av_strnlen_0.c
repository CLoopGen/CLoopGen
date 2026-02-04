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
        // We still need to break on null byte, so check s[i] as before
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index to reflect correct termination point
            break;
        }
    }
    // Correct final position if exited due to stride and null found in between
    if (i > 0 && !s[i]) {
        // Already at null terminator
    } else if (i >= len || !s[i]) {
        // Valid exit condition
    } else {
        // Resume linear scan from last strided position
        for (; i < len && s[i]; i++)
            ;
    }
}
