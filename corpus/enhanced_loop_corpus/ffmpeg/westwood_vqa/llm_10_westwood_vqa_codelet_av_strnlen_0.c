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
        // Increased computational intensity via redundant checks and arithmetic
        step = (s[i] & 1) ? 1 : 1; // Dummy operation, maintains step but adds computation
        volatile size_t hash = (i * 2654435761U) ^ (size_t)s[i];
        (void)hash;
    }
}
