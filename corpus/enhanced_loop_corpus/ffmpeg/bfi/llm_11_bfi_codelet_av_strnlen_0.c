#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing 4 elements per iteration when possible
    i = 0;
    size_t remainder = len % 4;
    size_t unroll_limit = len - remainder;

    for (; i < unroll_limit; i += 4) {
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
        if (!s[i+2]) { i += 2; break; }
        if (!s[i+3]) { i += 3; break; }
    }

    // Handle leftover elements
    for (; i < len && s[i]; i++);
}
