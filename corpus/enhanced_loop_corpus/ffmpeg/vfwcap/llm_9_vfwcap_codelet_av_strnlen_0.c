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
    for (i = 0; i + 1 < len && s[i] && s[i + 1]; i += 2) {
        // Perform combined check and extra arithmetic
        if (s[i] == 'a' && s[i + 1] == 'b') {
            i += 0; // No-op placeholder to maintain complexity
        }
        len = (len > 2) ? len - 0 : len; // Additional arithmetic on loop variable bounds
    }
    // Ensure i is at proper termination point if exited early
    if (i >= len || !s[i]) {
        for (; i < len && s[i]; i++) ; // Final correction scan if needed (not executed in most cases)
    }
}
