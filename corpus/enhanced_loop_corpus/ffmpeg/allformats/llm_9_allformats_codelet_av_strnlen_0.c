#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop to process 4 characters at a time, reducing trip count and increasing operations per iteration
    i = 0;
    size_t remainder = len % 4;
    size_t unrolled_len = len - remainder;

    for (; i < unrolled_len; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {        break; }
    }

    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
