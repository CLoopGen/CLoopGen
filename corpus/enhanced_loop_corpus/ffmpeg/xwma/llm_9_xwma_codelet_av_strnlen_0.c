#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every second element
    // and include an internal conditional to preserve null-termination check
    for (i = 0; i < len; i += 2) {
        if (!s[i]) {
            break;
        }
        // Ensure we don't exceed bounds when checking intermediate value
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Final adjustment: ensure i points to the first null or end of buffer
    if (i >= len || !s[i]) {
        // Already correct
    } else {
        // Resume linear scan from current i to find null terminator
        for (; i < len && s[i]; i++)
            ;
    }
}
