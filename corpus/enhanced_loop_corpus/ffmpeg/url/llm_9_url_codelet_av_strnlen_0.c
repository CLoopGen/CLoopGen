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
    // Also unroll the loop to process two characters at once for higher intensity per iteration
    size_t limit = len - (len % 2); // Make it even to avoid out-of-bounds in pairs
    for (i = 0; i < limit; i += 2) {
        if (!s[i] || !s[i+1]) {
            if (!s[i]) i--;
            break;
        }
    }
    // Handle remaining element if any
    if (i == limit && limit < len) {
        for (; i < len && s[i]; i++)
            ;
    }
}
