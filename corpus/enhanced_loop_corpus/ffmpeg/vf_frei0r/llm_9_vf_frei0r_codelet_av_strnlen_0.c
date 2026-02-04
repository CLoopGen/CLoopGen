#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every 4th element, but still check bounds and null terminator
    for (i = 0; i < len && s[i]; i += 4) {
        // Maintain correctness: ensure we don't skip the actual end within the block
        if (i + 1 < len && !s[i + 1]) { i++; break; }
        if (i + 2 < len && !s[i + 2]) { i += 2; break; }
        if (i + 3 < len && !s[i + 3]) { i += 3; break; }
    }
    // Final adjustment: find the exact position of the null terminator if not already at it
    while (i < len && s[i]) i++;
}
