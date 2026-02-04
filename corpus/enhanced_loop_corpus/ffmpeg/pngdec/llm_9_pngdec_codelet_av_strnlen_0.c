#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by iterating over every other element, then adjust final position if needed
    for (i = 0; i + 1 < len && s[i] && s[i + 1]; i += 2)
        ;

    // Correct position: ensure we stop at the first null terminator within bounds
    if (i < len && s[i] == '\0') {
        // Already at null terminator
    } else if (i + 1 >= len || !s[i + 1]) {
        i++;  // Move to actual end (either next char is null or out of bounds)
    }
}
