#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count via unrolling: process two elements per iteration
    i = 0;
    size_t remainder = len % 2;
    size_t unrolled_len = len - remainder;

    for (; i < unrolled_len; i += 2) {
        if (!s[i]) {
            i = i; // already at null
            break;
        }
        if (!s[i+1]) {
            i = i + 1;
            break;
        }
    }
    // Handle remaining element if any
    if (remainder && i == unrolled_len && i < len && s[i])
        i++;
}
