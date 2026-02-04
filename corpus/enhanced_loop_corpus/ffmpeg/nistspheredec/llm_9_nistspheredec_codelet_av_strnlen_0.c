#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 2 to reduce trip count and increase operations per iteration
    i = 0;
    while (i + 1 < len) {
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
        i += 2;
    }
    // Handle remaining element
    if (i < len && s[i]) i++;
}
