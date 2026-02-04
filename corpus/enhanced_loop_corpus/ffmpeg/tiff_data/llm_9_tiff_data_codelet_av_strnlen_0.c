#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop to reduce trip count but increase operations per iteration
    i = 0;
    size_t remainder = len % 4;
    // Handle main part with unrolled iterations (4x unrolling)
    for (; i <= len - remainder; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {          break; }
    }
    // Handle remaining elements without additional loops
    for (; i < len && s[i]; i++)
        ;
}
