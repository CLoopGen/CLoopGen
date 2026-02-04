#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple elements at once, assuming ASCII
    for (i = 0; i <= len - 8; i += 8) {
        // Unroll loop to process 8 characters per iteration with early exit if null found
        if (!s[i])     { i -= 7; break; }
        if (!s[i + 1]) { i -= 6; break; }
        if (!s[i + 2]) { i -= 5; break; }
        if (!s[i + 3]) { i -= 4; break; }
        if (!s[i + 4]) { i -= 3; break; }
        if (!s[i + 5]) { i -= 2; break; }
        if (!s[i + 6]) { i -= 1; break; }
        if (!s[i + 7]) {        break; }
    }
    // Handle remaining characters normally if unrolled loop didn't find null
    for (; i < len && s[i]; i++)
        ;
}
