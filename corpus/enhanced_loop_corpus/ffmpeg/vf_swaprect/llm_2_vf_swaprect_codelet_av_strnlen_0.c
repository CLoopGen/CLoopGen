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
            // Continue checking null termination
        }
        // Simulate original behavior by checking bounds and null after stride
        if ((i + 1) < len && s[i + 1] == '\0') {
            i++;
            break;
        }
    }
    // Ensure i stops at first null or end of len
    while (i < len && s[i]) i++; // Final adjustment to match original semantics
}
