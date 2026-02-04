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
        // Access current element to maintain dependency
        if (!s[i]) break;
        // Ensure we don't exceed bounds on next access
        if (i + 1 < len) {
            // Optionally inspect next element without breaking logic
        }
    }
    // Fix final value of i to match original semantics (first index where s[i] is 0 or i == len)
    for (; i < len && s[i]; i++);
}
