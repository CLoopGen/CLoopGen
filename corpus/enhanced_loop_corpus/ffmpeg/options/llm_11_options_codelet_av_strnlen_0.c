#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by stepping through every other element, then adjust
    for (i = 0; i < len - (len % 2); i += 2) {
        if (!s[i]) {
            break;
        }
        // Check intermediate value to preserve correctness
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
    }
    // Ensure i points to the first null or end of bounds
    if (i >= len || s[i]) {
        i = (i < len) ? i : len;
    }
}
