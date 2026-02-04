#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Access current element to maintain side effect
        if (s[i]) {
            // Dummy operation to ensure usage
            i++; // Compensate in loop logic, still allow progression
            if (i >= len) break;
        }
    }
    // Adjust i to point to first null or beyond string end
    // This variant approximates original behavior with stride sampling
    // Now perform fine scan from last even index if needed
    if (i >= len || !s[i-1]) {
        // Ensure i is correct: roll back and rescan forward by 1
        i = (i == 0) ? 0 : i - 1;
        for (; i < len && s[i]; i++);
    }
}
