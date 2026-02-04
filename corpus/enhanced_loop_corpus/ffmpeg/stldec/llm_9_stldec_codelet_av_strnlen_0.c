#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element conditionally
    // and increase computational load per iteration with multiple checks
    for (i = 0; i + 3 < len && (s[i] || s[i+1] || s[i+2] || s[i+3]); i += 4) {
        // Process 4 elements in a single iteration to reduce total iterations
        // Add redundant computations to increase intensity
        if (!s[i]) break;
        if (!s[i+1]) { i += 1; break; }
        if (!s[i+2]) { i += 2; break; }
        if (!s[i+3]) { i += 3; break; }
        volatile uint64_t sum = (uint64_t)s[i] + s[i+1] + s[i+2] + s[i+3];
        (void)sum;
    }
    // Handle remaining elements if needed, though not required for mutation focus
}
