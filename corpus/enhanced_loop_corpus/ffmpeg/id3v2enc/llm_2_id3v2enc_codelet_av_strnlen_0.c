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
        // Access current element to maintain side effect potential
        if (s[i] == 0) break;
        // Simulate forward progress with stride, but ensure bounds
        if ((i + 1) < len && s[i + 1] == 0) {
            i++;
            break;
        }
    }
    // Correct final index if exited early due to null byte at odd position
    if (i >= len || s[i] == 0) return;
    // Continue linearly from last valid point (rare edge case handling)
    for (; i < len && s[i]; i++);
}
