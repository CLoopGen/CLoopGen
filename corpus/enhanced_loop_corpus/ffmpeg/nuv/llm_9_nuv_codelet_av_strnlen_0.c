#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop to increase computational intensity and reduce trip count
    i = 0;
    size_t remainder = len % 4;
    // Handle unrolled part in chunks of 4
    for (; i < len - remainder; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {        break; }
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
