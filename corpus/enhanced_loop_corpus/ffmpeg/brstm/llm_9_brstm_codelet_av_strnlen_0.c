#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing two elements per iteration to reduce trip count
    size_t limit = len - (len % 2);
    for (i = 0; i < limit; i += 2) {
        if (!s[i]) { break; }
        if (!s[i + 1]) { i++; break; }
    }
    // Handle remaining element if any
    if (i == len - 1 && s[i]) { i++; }
}
