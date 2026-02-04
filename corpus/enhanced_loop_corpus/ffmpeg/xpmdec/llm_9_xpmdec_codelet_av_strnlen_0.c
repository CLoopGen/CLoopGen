#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 2 to reduce trip count and increase computational intensity per iteration
    i = 0;
    size_t remainder = len % 2;
    size_t unrolled_len = len - remainder;

    for (; i < unrolled_len; i += 2) {
        if (!s[i]) break;
        if (!s[i + 1]) {
            i++;
            break;
        }
    }

    // Handle leftover elements
    for (; i < len && s[i]; i++)
        ;
}
