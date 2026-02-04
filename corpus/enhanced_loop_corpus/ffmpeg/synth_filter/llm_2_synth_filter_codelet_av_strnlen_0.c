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
        // Skip every other character, but still check null terminator
        if ((i + 1) < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Adjust final index to point to first null or valid end
    if (i >= len || s[i] == '\0') {
        // i already correct
    } else {
        // Ensure we stop at proper boundary
        for (; i < len && s[i]; i++);
    }
}
