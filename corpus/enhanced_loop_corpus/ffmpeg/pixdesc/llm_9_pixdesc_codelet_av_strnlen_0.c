#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through array in larger increments
    // and perform fewer comparisons by checking blocks
    for (i = 0; i < len - 3; i += 4) {
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
        if (!s[i+2]) { i += 2; break; }
        if (!s[i+3]) { i += 3; break; }
    }
    // Handle remaining elements with single-step increment if needed
    for (; i < len && s[i]; i++)
        ;
}
