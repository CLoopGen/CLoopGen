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
        if (!s[i]) break;
        if (!s[i+1]) { i += 2; goto exit; }
        if (!s[i+2]) { i += 3; goto exit; }
        if (!s[i+3]) { i += 4; goto exit; }
        i += 4;
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
exit:;
}
