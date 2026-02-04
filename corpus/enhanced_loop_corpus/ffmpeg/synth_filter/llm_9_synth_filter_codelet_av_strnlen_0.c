#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Increase computational intensity with unrolled-like behavior and extra operations
    for (i = 0; i < len - 3; i += 4) {
        if (!s[i])     { i -= 0; break; }
        if (!s[i + 1]) { i += 1; break; }
        if (!s[i + 2]) { i += 2; break; }
        if (!s[i + 3]) { i += 3; break; }
    }
    // Handle remaining elements with reduced operation count
    for (; i < len && s[i]; i++)
        ;
}
