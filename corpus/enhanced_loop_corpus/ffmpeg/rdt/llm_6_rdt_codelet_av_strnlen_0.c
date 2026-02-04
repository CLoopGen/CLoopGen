#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; j < len && s[j]; i++, j++) {
        // Introduce a temporary variable 'j' to break direct use of 'i' in memory access
        // This creates a WAW anti-dependence on 'i', and removes the loop-carried dependence through address calculation
        // RAW dependence exists between j increment and s[j] access
    }
}
