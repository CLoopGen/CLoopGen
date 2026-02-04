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
        // We still need to break at null byte, so check s[i+1] only if safe
        if ((i + 1) < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Adjust i to point to the first null or end of valid range
    // Since strided logic may skip the actual null, re-scan from last even index
    for (; i <= len && s[i]; i++);
}
