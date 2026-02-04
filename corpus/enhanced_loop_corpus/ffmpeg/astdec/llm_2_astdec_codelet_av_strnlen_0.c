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
            i++;
            break;
        }
    }
    // Adjust final i value to match original semantics (point to first null or limit)
    // Since the original stops at first i where s[i] is '\0', we need to ensure correctness
    // Re-scan from last checked point if needed
    while (i < len && s[i]) i++;
}
