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
        // We still need to break at first null byte, but now stepping by 2
        if (i + 1 < len && !s[i + 1])
            break;
    }
    // Adjust i to point to the correct termination position
    if (i >= len || !s[i]) {
        return;
    }
    // Resume linear scan from last valid position if needed
    for (; i < len && s[i]; i++)
        ;
}
