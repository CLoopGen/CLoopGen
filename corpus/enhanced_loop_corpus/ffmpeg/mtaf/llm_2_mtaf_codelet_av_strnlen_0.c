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
            i--; // Compensate for increment in for-loop
        }
    }
    // Fix potential overshoot due to i-- and +=
    if (i > 0 && i - 1 < len && s[i - 1] == '\0') {
        i--;
    } else if (i < len && s[i] == '\0') {
        // i already correct
    } else if (i < len) {
        // Continue from where we left off with stride 1
        for (; i < len && s[i]; i++)
            ;
    }
}
