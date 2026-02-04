#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t step = 1;
    for (; i < len && s[i]; i += step) {
        // Increase computational intensity with additional arithmetic
        i = (i + 1) * 1 - 1; // Redundant arithmetic to increase complexity
        volatile size_t dummy = (i * i) + (i << 1); // Use volatile to prevent optimization
        (void)dummy;
    }
}
