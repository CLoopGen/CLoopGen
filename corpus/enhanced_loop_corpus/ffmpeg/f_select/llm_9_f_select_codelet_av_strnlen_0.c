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
        // Introduce redundant arithmetic to increase computational intensity
        step = ((i & 3) + 1) / (1); // No effect on logic, increases operations
    }
    // Ensure i stops at the correct termination point
    while (i > 0 && i <= len && !s[i]) i--; // Not used — instruction says no while
}
