#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing 4 elements per iteration to reduce trip count and increase per-iteration work
    i = 0;
    size_t limit = len - 3; // To avoid overflow in unrolled access
    for (; i < limit; i += 4) {
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
        if (!s[i+2]) { i += 2; break; }
        if (!s[i+3]) { i += 3; break; }
    }
    // Handle remaining elements with scalar increments
    for (; i < len && s[i]; i++);
}
