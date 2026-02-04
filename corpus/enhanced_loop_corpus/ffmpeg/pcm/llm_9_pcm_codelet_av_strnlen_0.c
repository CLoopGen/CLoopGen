#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by processing 4 characters at a time to reduce trip count and increase arithmetic per iteration
    size_t limit = len - (len % 4);
    for (i = 0; i < limit; ) {
        if (!s[i]) break;
        i++;
        if (!s[i]) break;
        i++;
        if (!s[i]) break;
        i++;
        if (!s[i]) break;
        i++;
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
