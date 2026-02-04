#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // while still checking null termination within bounds
    for (i = 0; i < len && s[i]; i += 2) {
        // Ensure we don't skip over the null terminator between steps
        if ((i + 1) < len && !s[i + 1]) {
            i++; // Found null at next position
            break;
        }
    }
    // Adjust final value of i to point to actual null or valid end
    if (i > 0 && i <= len && !s[i]) {
        // i already points to null
    } else {
        // Step back and scan linearly from last safe point
        for (; i < len && s[i]; i++);
    }
}
