#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with no change in trip count
    // Added arithmetic operations and condition checks per iteration
    for (i = 0; i < len && s[i] != '\0'; i++) {
        // Introduce additional arithmetic and dummy computations
        volatile size_t square = i * i;
        volatile size_t offset = (square + 3 * i + 2) % len;
        (void)square; (void)offset;
    }
}
