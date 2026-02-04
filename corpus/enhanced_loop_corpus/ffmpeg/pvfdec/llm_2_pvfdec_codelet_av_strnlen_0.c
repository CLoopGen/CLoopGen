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
        // Perform dummy access to maintain correctness
        // Since we're skipping elements, ensure bounds and null check are still valid
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index to point to terminating null if found in stride
            break;
        }
    }
    // Correct final position: if loop ended due to stride, verify actual termination
    if (i >= len || !s[i]) return;
    // Otherwise, continue linearly from last checked point
    for (; i < len && s[i]; i++);
}
