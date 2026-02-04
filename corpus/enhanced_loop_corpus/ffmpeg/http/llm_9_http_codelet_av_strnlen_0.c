#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop to process multiple elements per iteration, reducing trip count
    size_t limit = (len / 4) * 4;  // Round down to multiple of 4
    for (i = 0; i < limit; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {         break; }
    }
    // Handle remaining characters sequentially
    for (; i < len && s[i]; i++)
        ;
}
