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
    size_t limit = len - (len % 2); // Make it even to simplify unrolling
    for (; i < limit; i += 2) {
        if (!s[i] || !s[i+1]) {
            break;
        }
    }
    // Handle remaining element if any
    if (i == limit && i < len && s[i]) {
        i++;
    }
}
