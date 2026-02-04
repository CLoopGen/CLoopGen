#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by processing multiple elements per iteration
    // and unroll the loop partially to decrease iteration overhead
    size_t limit = len - (len % 4); // Align to multiple of 4
    for (i = 0; i < limit; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {        break; }
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
