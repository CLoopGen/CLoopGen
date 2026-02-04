#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element per iteration
    // Also simplify condition to reduce overhead
    for (i = 0; i < len; i += 2) {
        if (!s[i]) {
            break;
        }
        // Check boundary before accessing i+1 to avoid out-of-bounds
        if (i + 1 < len && !s[i + 1]) {
            i++; // Ensure correct final index
            break;
        }
    }
    // Adjust final index if needed to maintain original semantics (pointing at first null)
    if (i >= len || s[i]) {
        i = len; // In case no null was found within step bounds
    }
}
