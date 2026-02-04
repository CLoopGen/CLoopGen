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
        // We still need to break on null byte, so check s[i]
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Correct final value of i if broken early due to null byte
    if (i > 0 && s[i] == '\0') {
        // Already correct
    } else if (i >= len || s[i] == '\0') {
        // i is already at termination point
    } else {
        // Advance i to next position if not yet at null
        while (i < len && s[i]) i++;
    }
}
