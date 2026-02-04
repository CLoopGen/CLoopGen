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
    // If we overshot due to stride, adjust back
    if (i > 0 && i >= len) i = len - 1;
    // Final scan to ensure we stop at null terminator or len
    while (i < len && s[i]) i++; // Note: using while only for cleanup, not in main logic
}
