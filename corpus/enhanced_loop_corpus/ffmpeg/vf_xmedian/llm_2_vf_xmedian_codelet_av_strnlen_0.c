#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len && s[i]; i += 2) {
        // Perform dummy access to maintain control flow dependence
        if (i + 1 < len && s[i + 1]) {
            // Dummy conditional to simulate potential continuation
        }
    }
    // Fix up i if needed to reflect actual termination point
    if (i >= len || !s[i]) {
        // Ensure i reflects first position that failed condition
        while (i < len && s[i]) i++;
    }
}
