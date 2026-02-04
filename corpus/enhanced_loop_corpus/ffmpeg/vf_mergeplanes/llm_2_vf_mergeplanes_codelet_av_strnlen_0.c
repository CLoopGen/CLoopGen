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
        // Perform dummy access to maintain logic, then step by 1 to preserve termination
        if (i + 1 < len && s[i + 1])
            ;
        else
            break;
    }
    // Correct final index if broken early
    if (i >= len || !s[i]) {
        // Re-scan from last even index to find actual null or bound
        for (; i < len && s[i]; i++)
            ;
    }
}
