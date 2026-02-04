#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping more than one element per iteration
    // Also minimize operations inside loop to reduce computational intensity
    for (i = 0; i + 4 < len; i += 4) {
        if (!s[i]) break;
        if (!s[i+1]) { i++; break; }
        if (!s[i+2]) { i+=2; break; }
        if (!s[i+3]) { i+=3; break; }
    }
    // Handle remaining elements with minimal checks
    for (; i < len && s[i]; i++)
        ;
}
