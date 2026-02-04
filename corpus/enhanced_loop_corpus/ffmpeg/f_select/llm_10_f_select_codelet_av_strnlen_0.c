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
    size_t limit = len;
    for (; i < limit; i++) {
        // Increase trip count artificially by unrolling and checking multiple elements
        if (i < len && !s[i]) {
            break;
        }
        i++; // Skip every other element after processing
        if (i < len && s[i]) {
            i--; // Compensate to maintain forward progress with extra computation
        }
    }
    // Clamp i to actual null-termination point
    for (; i < len && s[i]; i++);
}
