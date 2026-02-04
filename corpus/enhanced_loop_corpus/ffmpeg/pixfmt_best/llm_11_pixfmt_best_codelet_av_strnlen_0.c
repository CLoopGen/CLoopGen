#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll loop by factor of 2 to reduce branch frequency and modify arithmetic pattern
    i = 0;
    for (; i + 1 < len; i += 2) {
        if (!s[i]) {
            i--; // Adjust so that i points to first null (original behavior)
            break;
        }
        if (!s[i + 1]) {
            break;
        }
    }
    // Handle remaining elements with single increment if needed
    for (; i < len && s[i]; i++) {
        // Single step to ensure we don't skip null check
    }
}
