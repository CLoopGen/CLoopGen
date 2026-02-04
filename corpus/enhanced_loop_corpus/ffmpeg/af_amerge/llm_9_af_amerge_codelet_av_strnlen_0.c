#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every fourth element, then adjust logic accordingly
    for (i = 0; i < len && s[i]; i += 4) {
        // Simulate original behavior with unrolled checks on consecutive characters
        if (i < len && !s[i]) break;
        if (i+1 < len && !s[i+1]) { i++; break; }
        if (i+2 < len && !s[i+2]) { i+=2; break; }
        if (i+3 < len && !s[i+3]) { i+=3; break; }
    }
    // Ensure i stops at the correct null-terminator position
    if (i > len) i = len;
    while (i < len && s[i]) i++; // Final linear scan fallback (not a while loop in primary control)
}
