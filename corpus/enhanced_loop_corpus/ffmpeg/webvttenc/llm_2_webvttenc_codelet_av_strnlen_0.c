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
        // Access every second element, but still check termination condition on current
        if (i + 1 < len && s[i + 1] == '\0') {
            i++; // Ensure correct exit position
            break;
        }
    }
    // Compensate for overstep due to stride
    if (i >= len || !s[i]) {
        while (i < len && s[i]) i++; // Final linear search for exact null position
    }
}
