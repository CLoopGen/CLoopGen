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
    i = 0;
    while (i + 4 < len) {
        if (!s[i+0]) break;
        if (!s[i+1]) { i += 1; goto end; }
        if (!s[i+2]) { i += 2; goto end; }
        if (!s[i+3]) { i += 3; goto end; }
        i += 4;
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
end:;
}
