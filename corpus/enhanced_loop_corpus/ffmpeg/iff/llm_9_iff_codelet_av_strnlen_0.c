#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 4 to reduce trip count and branch checks
    size_t remainder = len % 4;
    size_t unrolled_len = len - remainder;

    for (i = 0; i < unrolled_len; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {        break; }
    }

    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
