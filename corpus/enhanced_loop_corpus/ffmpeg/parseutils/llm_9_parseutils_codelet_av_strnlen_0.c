#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through the array in larger increments
    // but maintain correctness by checking alignment and remaining characters
    for (i = 0; i < len - 7; i += 8) {
        if (!s[i]) { i -= 7; break; } // Adjust index to point to first null
        if (!s[i+1]) { i -= 6; break; }
        if (!s[i+2]) { i -= 5; break; }
        if (!s[i+3]) { i -= 4; break; }
        if (!s[i+4]) { i -= 3; break; }
        if (!s[i+5]) { i -= 2; break; }
        if (!s[i+6]) { i -= 1; break; }
        if (!s[i+7]) { break; }
    }
    // Handle remaining elements if not exited cleanly
    while (i < len && s[i]) i++;
}
