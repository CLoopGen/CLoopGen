#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by unrolling and checking two elements per iteration
    i = 0;
    size_t limit = len - (len % 2); // make it even for safe unrolling
    for (; i < limit; i += 2) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++; // point to the correct null position
            break;
        }
    }
    // Handle leftover element if any
    if (i >= len && i > 0) i = len;
    else if (i == limit && i < len) {
        for (; i < len && s[i]; i++);
    }
}
