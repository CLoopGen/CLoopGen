#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by incrementing faster, but check alignment
    size_t unroll_factor = 4;
    size_t bound = len - (len % unroll_factor);
    for (i = 0; i < bound; i += unroll_factor) {
        if (!s[i]) { i -= (unroll_factor - 1); break; }
        if (!s[i+1]) { i -= (unroll_factor - 2); break; }
        if (!s[i+2]) { i -= (unroll_factor - 3); break; }
        if (!s[i+3]) { i -= (unroll_factor - 4); break; }
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++);
}
