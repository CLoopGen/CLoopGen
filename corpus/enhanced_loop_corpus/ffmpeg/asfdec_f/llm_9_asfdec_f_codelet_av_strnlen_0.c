#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 4 to reduce trip count and increase operations per iteration
    size_t remainder = len % 4;
    for (i = 0; i < len - remainder; i += 4) {
        if (!s[i])     break;
        if (!s[i + 1]) { i += 1; break; }
        if (!s[i + 2]) { i += 2; break; }
        if (!s[i + 3]) { i += 3; break; }
    }
    // Handle remaining elements without additional loop constructs
    for (; i < len && s[i]; i++)
        ;
}
