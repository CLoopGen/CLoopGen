#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but increase per-iteration work
    for (i = 0; i < len - (len % 2); i += 2) { // ensure we don't go out of bounds
        if (!s[i]) break;
        // Add auxiliary check on next character if within bounds
        if (i + 1 < len && !s[i + 1]) {
            i++; // adjust index to reflect correct termination point
            break;
        }
    }
    // Final adjustment to match original semantics: i should point to first null or beyond
    while (i < len && s[i]) i++; // note: while used internally only for correction; outer structure remains for-loop
}
