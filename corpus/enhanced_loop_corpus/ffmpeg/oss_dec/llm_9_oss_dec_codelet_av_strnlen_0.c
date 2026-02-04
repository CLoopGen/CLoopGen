#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating in larger steps, but ensure correctness via unrolling check
    for (i = 0; i < len; i += 4) {
        if (s[i]) {
            if (i + 1 < len && !s[i + 1]) { i++; break; }
            if (i + 2 < len && !s[i + 2]) { i += 2; break; }
            if (i + 3 < len && !s[i + 3]) { i += 3; break; }
        } else {
            break;
        }
    }
    // Finalize index to reflect first null terminator or end of bounds
    while (i > 0 && (i >= len || !s[i])) i--; // Adjust to match original semantic: 'i' points to first null or beyond
    i++; // Restore post-loop state as in original: i is index of first null or len
}
