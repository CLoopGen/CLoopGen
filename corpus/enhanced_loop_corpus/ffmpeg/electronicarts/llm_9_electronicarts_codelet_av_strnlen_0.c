#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 2 to reduce trip count and increase per-iteration work
    i = 0;
    while (i < len - 1) {
        if (!s[i]) break;
        if (!s[i+1]) { i += 2; break; }
        i += 2;
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
