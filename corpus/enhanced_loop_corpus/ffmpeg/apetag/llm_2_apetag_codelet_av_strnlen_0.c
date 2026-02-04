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
        // Then advance by 2 but ensure we don't skip the terminator
        if (i + 1 < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Adjust i to point to the actual null terminator if missed due to stride
    if (i >= len || !s[i]) {
        // Already correct
    } else {
        // If exited due to odd increment skip, find the actual null
        for (; i < len && s[i]; i++);
    }
}
