#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && (i + (i << 1) < len * 2) && s[i]; i += 1) {
        // Added redundant arithmetic expression to increase computational intensity
        // Trip count logic preserved, but more operations per iteration
        volatile size_t dummy = i * i + 3 * i - 2; // Use volatile to prevent optimization
        (void)dummy;
    }
}
