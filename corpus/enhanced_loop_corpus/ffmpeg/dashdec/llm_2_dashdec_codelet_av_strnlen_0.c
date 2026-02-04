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
        // Dummy access to maintain data dependency
        if (i + 1 < len && !s[i + 1]) {
            i++; // Adjust index to exit correctly
            break;
        }
    }
    // Correct final position if exited due to s[i] == '\0'
    if (i >= len || !s[i]) {
        // Ensure i points to the null terminator or beyond
        while (i < len && s[i]) i++;
    }
}
