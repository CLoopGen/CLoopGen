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
        // Perform dummy access to maintain logic, then step back
        if ((i + 1) < len && s[i + 1]) {
            // Simulate forward progress check without altering control flow directly
        }
        // Continue actual increment in loop expression
    }
    // Correct final index by checking missed elements due to stride
    if (i >= len || !s[i]) {
        // If current i is invalid, backtrack and scan linearly from last even index
        size_t start = (i == 0) ? 0 : i - 1;
        for (i = start; i < len && s[i]; i++)
            ;
    }
}
