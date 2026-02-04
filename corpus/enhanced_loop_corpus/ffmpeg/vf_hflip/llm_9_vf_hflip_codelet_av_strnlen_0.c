#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every other element
    // Also simplify condition to reduce per-iteration checks
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) break;
    }
    // Ensure i stops at first null terminator within bounds
    if (i > 0 && i % 2 != 0) i--; // Adjust alignment if needed
    while (i < len && s[i]) i++; // Final linear scan from adjusted position
}
