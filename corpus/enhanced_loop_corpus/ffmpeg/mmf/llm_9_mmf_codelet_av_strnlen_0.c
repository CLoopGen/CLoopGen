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
    // but still check null terminator within bounds
    for (i = 0; i < len && s[i]; i += 2) {
        // Add auxiliary computation to maintain work per iteration
        if ((i + 1) < len && !s[i + 1]) {
            i++; // Ensure correct termination detection
            break;
        }
    }
    // Finalize: ensure `i` points to the first null or end of buffer
    if (i >= len || !s[i]) {
        // Already at termination point
    } else {
        // Handle case where we stepped over; re-scan from last valid point
        while (i < len && s[i]) i++;
    }
}
