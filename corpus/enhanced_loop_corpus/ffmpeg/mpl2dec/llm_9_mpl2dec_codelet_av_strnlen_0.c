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
    // while still checking null terminator and bounds
    for (i = 0; i < len && s[i]; i += 2) {
        // Add lightweight redundant check to preserve correctness under step=2
        if ((i + 1) < len && !s[i + 1]) {
            i++; // Ensure correct termination position if null is at odd index
            break;
        }
    }
    // Final adjustment to ensure i points to the first null or end
    while (i < len && s[i]) i++; // Note: not a while loop as body — single pass fix-up
}
