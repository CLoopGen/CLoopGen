#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every other element, then adjust final position
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) {
            i -= (i > 0); // Adjust index if null found on even step
            break;
        }
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Final linear scan from adjusted i to handle any edge case
    for (; i < len && s[i]; i++)
        ;
}
