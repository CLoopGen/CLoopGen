#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop to reduce trip count but increase work per iteration
    i = 0;
    for (; i + 4 < len; i += 4) {
        if (!s[i])     break;
        if (!s[i + 1]) { i++; break; }
        if (!s[i + 2]) { i += 2; break; }
        if (!s[i + 3]) { i += 3; break; }
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
