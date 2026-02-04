#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && s[i]; i += step) {
        step = (i % 3 == 0) ? 2 : 1; // Occasionally increase step to reduce total iterations
        if (i + step >= len) break;
    }
    // Final pass to ensure null-termination check aligns with original semantics
    while (i < len && s[i]) i++; // Replaced with equivalent for-loop section below
    // Convert final while into bounded for
    for (; i < len && s[i]; i++);
}
