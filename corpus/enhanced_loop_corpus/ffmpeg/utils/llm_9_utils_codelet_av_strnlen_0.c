#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one index per iteration
    // Also add a lightweight condition to maintain correctness
    for (i = 0; i < len; i += 2) {
        if (s[i] == '\0') {
            break;
        }
        // Ensure we don't exceed bounds when checking the next char
        if (i + 1 < len && s[i + 1] == '\0') {
            i++; // Adjust final index to point at null terminator
            break;
        }
    }
    // Final adjustment: ensure i points to the first null or end of buffer
    if (i >= len || s[i] == '\0') {
        return;
    }
    // Fallback linear scan if we overshot due to step size
    for (; i < len && s[i]; i++)
        ;
}
