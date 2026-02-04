#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but perform more work per iteration
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform multiple checks to maintain correctness despite larger step
        if (i + 1 < len && !s[i + 1]) {
            i++;  // Adjust final index if null terminator found at next position
            break;
        }
    }
    // Ensure i points to the correct termination position (either null or len)
    if (i > len || (i > 0 && s[i])) i--; // Back up if we overshot due to step size
    while (i < len && s[i]) i++; // Final linear scan from adjusted position (emulated as single pass)
}
