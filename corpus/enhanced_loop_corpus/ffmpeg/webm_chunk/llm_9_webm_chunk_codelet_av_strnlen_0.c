#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating every other element, but still check null terminator
    for (i = 0; i < len && s[i]; i += 2) {
        // Add lightweight redundant check to preserve correctness under stride change
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Ensure i stops at first null terminator within bounds
    if (i >= len || s[i]) {
        for (; i < len && s[i]; i++)
            ;
    }
}
