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
        if (!s[i]) break;
        // Ensure we don't exceed bounds when checking next odd index
        if ((i + 1) < len && s[i + 1]) {
            i++; // Compensate to progress naturally through valid characters
        }
    }
}
