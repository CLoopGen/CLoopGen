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
        // Since we're skipping elements, we need to ensure termination condition still makes sense
        // We check every other character but must avoid out-of-bounds
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Adjust i to point to the actual null terminator or limit
    // If loop ended due to stride and we missed the null, correct it
    if (i >= len || !s[i]) {
        return;
    }
    // Otherwise, resume linear scan from last checked position
    for (; i < len && s[i]; i++)
        ;
}
