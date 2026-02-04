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
        // Access current element to maintain data dependency
        if (s[i]) {
            // Dummy operation to ensure the access is not optimized away
        }
        // Ensure we don't overflow on next iteration
        if ((i + 1) < len && s[i + 1]) {
            i++; // Compensate stride by adjusting increment within body
            break;
        }
    }
    // Correct final index if exited early due to strided logic
    for (; i < len && s[i]; i++) {
        break;
    }
}
