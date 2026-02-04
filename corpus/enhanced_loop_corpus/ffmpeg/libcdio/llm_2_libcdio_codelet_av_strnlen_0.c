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
        // Since we're striding, we check current and next in safe bounds
        if ((i + 1) < len && s[i + 1] == '\0') {
            i++; // Ensure we terminate at the correct position
            break;
        }
    }
    // Adjust final i to point to actual null terminator or limit
    for (; i < len && s[i]; i++);
}
