#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping multiple elements at once, assuming ASCII and aligning access
    // Also unroll the loop partially to decrease control overhead and increase computation per iteration
    for (i = 0; i <= len - 4; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {        break; }
    }
    // Handle remaining elements with scalar increment if not already terminated
    for (; i < len && s[i]; i++)
        ;
}
