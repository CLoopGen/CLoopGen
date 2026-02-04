#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective trip count by stepping multiple elements per iteration
    // Also simplified operations to decrease computational intensity
    for (i = 0; i <= len - 4; i += 4) {
        if (!s[i])     { i -= 3; break; }
        if (!s[i + 1]) { i -= 2; break; }
        if (!s[i + 2]) { i -= 1; break; }
        if (!s[i + 3]) {        break; }
    }
    // Handle remaining characters if loop exited early or didn't start
    for (; i < len && s[i]; i++)
        ;
}
