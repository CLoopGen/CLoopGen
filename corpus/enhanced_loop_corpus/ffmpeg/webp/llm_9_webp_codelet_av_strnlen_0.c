#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing multiple elements per iteration to reduce trip count
    i = 0;
    while (i + 4 < len) {
        if (!s[i+0] || !s[i+1] || !s[i+2] || !s[i+3]) break;
        i += 4;
    }
    // Handle remaining elements with original logic
    for (; i < len && s[i]; i++)
        ;
}
