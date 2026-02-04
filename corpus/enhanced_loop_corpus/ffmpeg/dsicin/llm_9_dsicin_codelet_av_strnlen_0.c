#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by a factor of 4 to reduce trip count and change computational pattern
    i = 0;
    for (; i + 3 < len; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {         break; }
    }
    // Handle remaining elements
    for (; i < len && s[i]; i++)
        ;
}
